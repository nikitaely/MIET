`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/08/2024 02:04:46 PM
// Design Name: 
// Module Name: data_mem
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


module data_mem(
input logic clk_i,
input logic mem_req_i,
input logic write_enable_i,
input logic [31:0] addr_i,
input logic [31:0] write_data_i,
output logic [31:0] read_data_o  
    );
logic [31:0] ram[0:4095];
logic [13:2]counter;
//logic [13:2]counter_last;
logic [31:0]data;
logic [1:0] cmd;

//initial
//begin
//counter=0;
//data=0;
//end

assign cmd={write_enable_i,mem_req_i};
//assign read_data_o= ram[counter];
assign counter=addr_i[13:2];

always_ff @(posedge clk_i)
begin
   case(cmd)
   
    2'b01:  begin
                read_data_o<=ram[counter];
                data<=ram[counter];
            end
    2'b11:  begin
                read_data_o<=ram[counter];
                ram[counter]<=write_data_i;
                data<=ram[counter];
            end
    
    default:
   read_data_o<=data;
   endcase
end


    
endmodule
