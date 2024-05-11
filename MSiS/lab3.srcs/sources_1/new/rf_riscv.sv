`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/08/2024 03:45:10 PM
// Design Name: 
// Module Name: rf_riscv
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module rf_riscv(
input logic  clk_i,
input logic write_enable_i,
input logic [ 4:0] write_addr_i,
input logic [ 4:0] read_addr1_i,
input logic [ 4:0] read_addr2_i,

input logic [31:0] write_data_i,
output logic [31:0] read_data1_o,
output logic [31:0] read_data2_o
    );

logic [31:0]rf_mem[0:31];
logic [31:0]buf1;
logic [31:0]buf2;
//assign [7:0]rf_mem[0]=0;

assign buf1=rf_mem[ read_addr1_i ];
assign buf2=rf_mem[ read_addr2_i ];
/*
initial begin
    $readmemh("program.mem",rf_mem);
    
end
*/
always_comb
begin
    
    case(read_addr1_i)
        0: read_data1_o<=0;
    default:
        read_data1_o<=buf1;
    endcase
   
end

always_comb
begin
    
    case(read_addr2_i)
        0: read_data2_o<=0;
    default:
        read_data2_o<=buf2;
    endcase
    
end

always_ff @(posedge clk_i)
begin
    if (write_enable_i==1)
    begin
        rf_mem[ write_addr_i ]<=write_data_i;
    end   
end


endmodule
