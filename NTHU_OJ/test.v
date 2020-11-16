`timescale 1ns/1ps

module Decode_and_Execute (op_code, rs, rt, rd);
input [3-1:0] op_code;
input [4-1:0] rs, rt;
output [4-1:0] rd;
wire[4-1:0] a1, a2, a3, a4, a5, a6, a7, a8;
//add
Full_Adder_4bits FA_4bits1(rs, rt, 1'b0, a1);
//sub
Sub S1(rs, rt, a2);
//inc
Full_Adder_4bits FA_4bits2(rs, 4'b0001, 1'b0,a3);
//nor
nor nor1[4-1:0](a4, rs, rt);
//nand
nand nand1[4-1:0](a5, rs, rt);
//div
div div1(rs, a6);
//mul
mul mul1(rs, a7);
//multiplier
multiplier mul2(rs, rt, a8);

mux_8_to_1 m81(a1, a2, a3, a4, a5, a6, a7, a8, op_code, rd);

endmodule

module mux_8_to_1(a1, a2, a3, a4, a5, a6, a7, a8, sel, f);
input [4-1:0]a1, a2, a3, a4, a5, a6, a7, a8;
input [3-1:0] sel;
output[4-1:0]f;
wire [4-1:0] f1, f2, f3, f4, f5, f6;
mux_2_to_1 mux1(a1, a2, sel[0], f1);
mux_2_to_1 mux2(a3, a4, sel[0], f2);
mux_2_to_1 mux3(a5, a6, sel[0], f3);
mux_2_to_1 mux4(a7, a8, sel[0], f4);
mux_2_to_1 mux5(f1, f2, sel[1], f5);
mux_2_to_1 mux6(f3, f4, sel[1], f6);
mux_2_to_1 mux7(f5, f6, sel[2], f);

endmodule

module mux_2_to_1(a, b, sel, f);
input [4-1:0] a, b;
input sel;
output [4-1:0] f;
wire[4-1:0] sel_4bits;
wire[4-1:0] sel_bar;

not not1(sel_bar[3], sel_bar[2], sel_bar[1], sel_bar[0], sel);
not not2[3:0](sel_bar, sel_4bits);
assign f = a * sel_bar + b * sel_4bits;

endmodule


module multiplier(a, b, rd);
input [4-1:0] a, b;
output [4:0] rd;

wire [1:0] val1, val2, val3;
assign rd[0] = a[0] * b[0];
assign val1 = a[1] * b[1] + a[0] * b[1];
assign rd[1] = val1[0];
assign val2 = a[2] * b[0] + a[1] * b[1] + a[0] * b[2] + val1[1];
assign rd[2] = val2[0];
assign val3 = a[3] * b[0] + a[2] * b[1] + a[1] * b[2] + a[0] * b[3] + val2[1];
assign rd[3] = val3[0];

endmodule

module mul(rs, rd);
input [4-1:0] rs;
output[4-1:0] rd;

and and1(rd[3], rs[2], rs[2]);
and and2(rd[2], rs[1], rs[1]);
and and3(rd[1], rs[0], rs[0]);
and and4(rd[0], 1'b0, 1'b0);

endmodule

module div(a, f);
input[4-1:0] a;
output [4-1:0] f;

and and1(f[3], 1'b0, 1'b0);
and and2(f[2], 1'b0, 1'b0);
and and3(f[1], a[3], a[3]);
and and4(f[0], a[2], a[2]);

endmodule

module Sub (rs, rt, rd);
input [4-1:0] rt, rs;
output [4-1:0] rd;
wire [4-1:0] rt_bar;

not rt_bar1[3:0](rt, rt_bar);
Full_Adder_4bits FA_4bits1(rt_bar, rs, 1'b1, rd);

endmodule

module Full_Adder(a, b, cin, cout, sum);
input a, b, cin;
output cout, sum;
wire a_xor_b, ab, a_xor_bcin;
//sum
//xor a_xor_b1(a, b, a_xor_b);
//xor sum1(a_xor_b, cin, sum);

assign sum = a ^ b ^ cin;
//cout
//and ab1(ab, a, b);
//and a_xor_bcin1(a_xor_bcin, a_xor_b, cin);
//or cout1(cout, a_xor_bcin, ab);
assign cout = a*b + (a^b)*cin;
endmodule

module Full_Adder_4bits(a, b, cin, sum);
input[4-1:0] a, b;
input cin;
output[4-1:0] sum;
wire cout1, cout2, cout3, cout4;

Full_Adder FA1(a[0], b[0], cin, cout1, sum[0]);
Full_Adder FA2(a[1], b[1], cout1, cout2, sum[1]);
Full_Adder FA3(a[2], b[2], cout2, cout3, sum[2]);
Full_Adder FA4(a[3], b[3], cout3, cout4, sum[3]);

endmodule

module Xor(a, b, f);
input a, b;
output f;

wire a_bar, b_bar, ab_bar, a_barb;

not a_bar1(a_bar, a);
not b_bar1(b_bar, b);

and ab_bar1(ab_bar, a, b_bar);
and a_barb1(a_barb, a_bar, b);

or or1(f, ab_bar, a_barb);

endmodule