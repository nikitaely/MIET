`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/08/2024 12:34:23 PM
// Design Name: 
// Module Name: instr_mem
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


module instr_mem(
input logic [31:0] addr_i,
output logic [31:0]read_data_o
    );
logic [31:0] progmem [0:1023];

initial begin
    $readmemh("program.mem",progmem);
    
end


assign read_data_o=progmem[ addr_i[11:2] ];
 

endmodule
