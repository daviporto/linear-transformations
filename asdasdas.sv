//fvgrbfbr
//ybduebd
module test_circuito_personalizado;

  reg A, B, C, D;
  wire [2:0] Saida;
  
  circuito_personalizado UUT (
    .A(A),
    .B(B),
    .C(C),
    .D(D),
    .Saida(Saida)
  );

  initial begin
      $dumpfile("dump.vcd");
        $dumpvars;
    
    A = 0;
    B = 0;
    C = 1;
    D = 0;

    $display("Entradas: A=%b, B=%b, C=%b, D=%b, Saida=%b", A, B, C, D, Saida);
    #10;
    
    A = 1;
    B = 0;
    C = 1;
    D = 1;
    
    $display("Entradas: A=%b, B=%b, C=%b, D=%b, Saida=%b", A, B, C, D, Saida);
    #10;
    
    A = 1;
    B = 1;
    C = 1;
    D = 1;
    
    $display("Entradas: A=%b, B=%b, C=%b, D=%b, Saida=%b", A, B, C, D, Saida);
    #10;
    
    A = 1;
    B = 0;
    C = 1;
    D = 0;
    
    $display("Entradas: A=%b, B=%b, C=%b, D=%b, Saida=%b", A, B, C, D, Saida);
    #10;
    
    A = 1;
    B = 1;
    C = 0;
    D = 0;
    
    $display("Entradas: A=%b, B=%b, C=%b, D=%b, Saida=%b", A, B, C, D, Saida);
    #10;

    $finish;
  end
endmodule
