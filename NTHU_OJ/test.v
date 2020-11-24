`timescale 1ns/1ps

module Traffic_Light_Controller (clk, rst_n, lr_has_car, hw_light, lr_light);
    input clk, rst_n;
    input lr_has_car;
    output [3-1:0] hw_light;
    output [3-1:0] lr_light;

    parameter S0 = 3'd0;
    parameter S1 = 3'd1;
    parameter S2 = 3'd2;
    parameter S3 = 3'd3;
    parameter S4 = 3'd4;
    parameter S5 = 3'd5;
    
    assign hw_light[0] = (state >= 3'd2);
    assign hw_light[1] = (state == S1);
    assign hw_light[2] = (state == S0);
    assign lr_light[0] = (state != S3 && state != S4);
    assign lr_light[1] = (state == S4);
    assign lr_light[2] = (state == S3);
    
    reg [2:0] state, next_state;
    reg [5:0] count, next_count;
    
    always @(posedge clk) begin
        if (!rst_n) begin
            state <= S0;
            count <= 6'b0;
        end
        else begin
            state <= next_state;
            count <= next_count;
        end
    end
    
    always @(*) begin
        
        case (state)
            S0: begin
                next_state = (lr_has_car && (count >= 34) ? S1 : S0);
                next_count = (next_state == S1 ? 6'b0 : count + 6'b1);
            end 
            
            S1: begin
                next_state = (count == 6'd14 ? S2 : S1);
                next_count = (next_state == S2 ? 6'b0 : count + 6'b1);
            end 
            
            S2: begin
                next_state = S3;
                next_count = 6'b0;
            end 
            
            S3: begin
                next_state = (count == 6'd34 ? S4 : S3);
                next_count = (next_state == S4 ? 6'b0 : count + 6'b1);
            end 
            
            S4: begin
                next_state = (count == 6'd14 ? S5 : S4);
                next_count = (next_state == S5 ? 6'b0 : count + 6'b1);
            end 
            
            S5: begin
                next_state = S0;
                next_count = 6'b0;
            end 
    end
    
endmodule
