`timescale 1ns/1ps

module M1 (clk, in, out);
    input clk, in;
    output out;
    
    reg next_out;
    reg [2:0] count, next_count;
    reg trigger, next_trigger;
    
    always @(posedge clk) begin
        out <= next_out;
        count <= next_count;
        trigger <= next_trigger;
    end
    
    always @(*) begin
        
        next_trigger = in;
        next_out = (trigger || (count == 3'd3) ? ~out : out);
        next_count = (count == 3'd3 || trigger ? 3'd0 : count + 3'd1);
        
    end
endmodule
