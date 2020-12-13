always @(posedge clk) begin
    if (!rst_n)
        state <= IDLE;
        result <= 1'b1;
    else
        state <= next_state;
        result <= next_result;
end

wire out = (state == 3rd) && result;

always @(*) begin
    
    case (state)
        IDLE: begin
            next_state = 1st;
            next_result = in & result;  // detect 1.
        end
        1st : begin
            next_state = 2nd;
            next_result = ~in & result; // detect 0.
        end
        2nd : begin
            next_state = 3rd;
            next_result = ~in & result; // detect 0.
        end
        3rd : begin
            next_state = IDLE;
            next_result = ~in & result; // detect 0.
        end
end
