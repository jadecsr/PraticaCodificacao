import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Date;
import java.util.LinkedList;
import java.util.Scanner;

public class IES {

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        BufferedReader buffer;
        FileReader filerR;
        String file;

        file = leitor.next();

        final String dir = System.getProperty("user.dir");

        file = dir + "/" + file;

        try {
            filerR = new FileReader(file);
            buffer = new BufferedReader(filerR);

            while ((linhaAtual = buffer.readLine()) != null) {
                
            }
                        
            
        } catch (Exception e) {
            System.out.println("ARQUIVO NÃO ENCONTRADO!!!!");
        }

    }

    public class voo {

        Date data;
        String hora, operacao, matricula, origem, destino, tipo;

        public voo(Date data, String hora, String operacao, String matricula, String origem, String destino, String tipo) {
            this.data = data;
            this.hora = hora;
            this.operacao = operacao;
            this.matricula = matricula;
            this.origem = origem;
            this.destino = destino;
            this.tipo = tipo;
        }

        public Date getData() {
            return data;
        }

        public void setData(Date data) {
            this.data = data;
        }

        public String getHora() {
            return hora;
        }

        public void setHora(String hora) {
            this.hora = hora;
        }

        public String getOperacao() {
            return operacao;
        }

        public void setOperacao(String operacao) {
            this.operacao = operacao;
        }

        public String getMatricula() {
            return matricula;
        }

        public void setMatricula(String matricula) {
            this.matricula = matricula;
        }

        public String getOrigem() {
            return origem;
        }

        public void setOrigem(String origem) {
            this.origem = origem;
        }

        public String getDestino() {
            return destino;
        }

        public void setDestino(String destino) {
            this.destino = destino;
        }

        public String getTipo() {
            return tipo;
        }

        public void setTipo(String tipo) {
            this.tipo = tipo;
        }

    }

}
