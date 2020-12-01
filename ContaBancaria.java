// PROGRAMA PRINCIPAL 

public class Executar {
    private static double valor;
    
    public static void main(String[] args){
        conta outra_conta = new conta();
        conta minha_conta = new conta();
        
        Scanner input = new Scanner(System.in);
        
        String nome;
        int opcao, numero;
        float saldo, limite, saldo2 = 0, limite2 = 0;
        
        do{
            System.out.println("----- * Menu * -----");
            System.out.println("\n -> Conta Bancaria <- \n");
            System.out.println("1 - Inserir dados:");
            System.out.println("2 - Depositar");
            System.out.println("3 - Sacar");
            System.out.println("4 - Transferir");
            System.out.println("5 - Sair \n---------------------------");
            System.out.print("Digite uma opção: ");
            opcao = input.nextInt();
            
            
            switch(opcao){
                case 1:
                    System.out.print("\nInsira o nome:"); 
                    nome = input.next();
                    
                    System.out.print("Insira o numero: "); 
                    numero = input.nextInt();

                    System.out.print("Insira o saldo: "); 
                    saldo = input.nextFloat();
                    
                    System.out.print("Insira o limite: ");
                    limite = input.nextFloat();
                    
                    minha_conta.dados(nome, numero, saldo, limite);
                    break;
                    
                case 2:
                    System.out.print("\nInsira o valor do deposito: ");
                    valor = input.nextDouble();
                    minha_conta.deposita(valor);
                    break;
                    
                case 3:
                    System.out.print("\nInsira o valor que deseja sacar: ");
                    valor = input.nextDouble();
                    minha_conta.saca(valor);
                    break;
                    
                case 4:
                    System.out.print("\nInsira o valor que deseja transferir: ");
                    valor = input.nextDouble();
                    
                    System.out.print("\nInsira o nome:"); 
                    nome = input.next();
                    
                    System.out.print("Insira o numero: "); 
                    numero = input.nextInt();
                    
                    outra_conta.dados(nome, numero, saldo2, limite2);
                    minha_conta.transfere(outra_conta, valor);
                    break;
                    
                case 5:
                    System.out.println("\n\nSaindo...");
                    break;
                    
                default:
                    break;
            }
        }while(opcao != 5);
    }
}

// CLASSE DE REGISTRO 

public class conta{
    private int numero;
    private double saldo;
    private double limite;
    private String nome;
    
    public conta() {
        this.numero=0;
        this.nome=" ";
        this.saldo=0;
        this.limite=0; 
    }
    //geradas automaticamente
    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
            
    //feitas para execução do programa
    void dados(String a, int b, float c, float d){
        this.nome = a;
        this.numero = b;
        this.saldo = c;
        this.limite = d;
    }
    
    public boolean saca(double valor){
        if(this.saldo < valor){
            System.out.println("\nValor maior do que o presente em conta!");
            return false;
        }else{
            this.saldo = this.saldo - valor;
            System.out.println("\nSaque realizado com sucesso!");
            return  true;
        }
    }  
    
    public void deposita(double valor){
        this.saldo = this.saldo + valor;
        System.out.println("\nDeposito realizado com sucesso!");
    }
    
    public void transfere(conta destino, double valor){
        if(this.saldo < valor){
            System.out.println("\nValor maior do que o presente em conta!");
        }else{
            this.saldo = this.saldo - valor;
            System.out.println("\nTransferencia realizada com sucesso!");
        }
    }
}
