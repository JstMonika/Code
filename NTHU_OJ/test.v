module machine(clk, rst, in, out, state);
    input clk, rst;
    input [1:0] in;
    output out;
    output [1:0] state;

    parameter S0 = 2'd0;
    parameter S1 = 2'd1;
    parameter S2 = 2'd2;
    parameter S3 = 2'd3;
    
    reg [1:0] state, next_state;
    
    always @(posedge clk) begin
        
        if (!rst)
            state <= 2'b0;
        else
            state <= next_state;
            
    end
    
    assign out = in;
    
    wire go_next;
    nand and1(go_next, in[0], in[1]);
    always @(*) begin
        
        case (state)
            S0: begin
                next_state = (in[0] | in[1] ? S1 : S0);
            end
            
            S1: begin
                
            end
            
            S2: begin
                
            end
            
            S3: begin
                
            end
            
        endcase
    end
    
endmodule