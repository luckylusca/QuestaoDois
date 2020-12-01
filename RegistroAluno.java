// PROGRAMA EXECUTAVEL

public class Executar {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        RegistroAluno cal_media = new RegistroAluno();
        
        int pe, pt, pp, opcao;
        float nota1, nota2, nota3;
        String nome;
        
        do{
            System.out.println("----- MENU -----");
            System.out.println(" 1 - Registrar aluno");
            System.out.println(" 2 - Sair");
            System.out.println("\n\nOBS -> O peso válido paras as notas é '1' \n\n");
            System.out.println("----------------");
            System.out.print("Digite uma opção: ");
            opcao = input.nextInt();
            
            switch(opcao){
                case 1:
                    System.out.print("\n\nRegistro do Aluno\nInsira o nome: ");
                    nome = input.next();
                    
                    System.out.print("\nInsira a nota do exercicio: ");
                    nota1 = input.nextFloat();
                    System.out.print("Insira seu peso: ");
                    pe = input.nextInt();
                    
                    System.out.print("\nInsira a nota do trabalho: ");
                    nota2 = input.nextFloat();
                    System.out.print("Insira seu peso: ");
                    pt = input.nextInt();
                    
                    System.out.print("\nInsira a nota da prova: ");
                    nota3 = input.nextFloat();
                    System.out.print("Insira seu peso: ");
                    pp = input.nextInt();
                    
                    cal_media.aluno(nome, nota1, nota2, nota3);
                    System.out.print("\nMédia: "+cal_media.calcularMedia(pe, pt, pp));
                    
                    break;
                    
                case 2:
                    break;
                    
                default:
                    break;
            }
            System.out.println("");
        }while(opcao != 2);
    }
}

// CLASSE DE REGISTRO

public class RegistroAluno {
    private String nomeAluno;
    private float notaExer;
    private float notaTrab;
    private float notaProv;
    private float media;
    
    public RegistroAluno(){
        this.nomeAluno = " ";
        this.notaExer = 0;
        this.notaTrab = 0;
        this.notaProv = 0;
        this.media = 0;
    }

    public float getMedia() {
        return media;
    }

    public void setMedia(float media) {
        this.media = media;
    }
    
    public String getNomeAluno() {
        return nomeAluno;
    }

    public void setNomeAluno(String nomeAluno) {
        this.nomeAluno = nomeAluno;
    }

    public float getNotaExer() {
        return notaExer;
    }

    public void setNotaExer(float notaExer) {
        this.notaExer = notaExer;
    }

    public float getNotaTrab() {
        return notaTrab;
    }

    public void setNotaTrab(float notaTrab) {
        this.notaTrab = notaTrab;
    }

    public float getNotaProv() {
        return notaProv;
    }

    public void setNotaProv(float notaProv) {
        this.notaProv = notaProv;
    }
   
    
    void aluno(String nome, float nota1, float nota2, float nota3){
        this.nomeAluno = nome;
        this.notaExer = nota1;
        this.notaTrab = nota2;
        this.notaProv = nota3;
    }
    
    public double calcularMedia(int pe, int pt, int pp){
        if(pe != 1 || pt != 1 || pp != 1){
            System.out.println("\nPeso referente as notas estão inválidas");
            return this.media;
        }else{
            this.media = ((this.notaExer * pe) + (this.notaTrab * pt) + (this.notaProv * pp)) / 3;
            return this.media;
        }
    }
}
