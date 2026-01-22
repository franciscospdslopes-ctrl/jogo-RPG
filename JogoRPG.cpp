  //Ex1 (69-81)
  //Ex2 (32-34) main(117-119)
  //Ex3 (49-52)
  //extra (101)
  
  #include <iostream>
  #include <string>
  using namespace std;
  
  class Personagem {
  protected: // Encapsulamento: Protegido permite acesso às classes filhas
      string nome;
      int vida;
      int vidaMaxima;
  
  public:
      // Construtor
      Personagem(string n, int v) : nome(n), vida(v), vidaMaxima(v) {}

    // Getters (Encapsulamento: Leitura segura)
    string getNome() const { return nome; }
    int getVida() const { return vida; }

    // Método para sofrer dano (Lógica encapsulada)
    void receberDano(int dano) {
        vida -= dano;
        if (vida < 0) vida = 0;
        cout << nome << " sofreu " << dano << " de dano! Vida restante: " << vida << endl;
    }

    // Método genérico de ataque
    void atacar() {
        cout << nome << " fez um ataque basico." << endl;
    }
  
    bool estaVivo() {
        if (vida > 0) {
            cout << nome << " esta vivo com " << vida << " de vida." << endl;
        } else {
            cout << nome << " esta morto." << endl;
        }
        return vida > 0;
    }

};
class Guerreiro : public Personagem {
    private:
        int forca; // Atributo exclusivo do Guerreiro
    
    public:
        // Construtor do Guerreiro chama o construtor do Pai (Personagem)
        Guerreiro(string n, int v, int f) : Personagem(n, v), forca(f) {}
    
        // Sobrescrita do método atacar
       
        void atacar(Personagem &alvo) {
            cout << nome << " brande a sua espada com forca " << forca << "!" << endl;
            alvo.receberDano(forca);
        }
    
        // Método exclusivo
        void gritoDeGuerra() {
            cout << nome << " grita: POR SPARTA!!" << endl;
        }
    };
    
    class Mago : public Personagem {
    private:
        int magia; // Atributo exclusivo do Mago
    
    public:
        Mago(string n, int v, int m) : Personagem(n, v), magia(m) {}
    
        void atacar() {
            cout << nome << " lanca uma bola de fogo com poder " << magia << "!" << endl;
        }
    
        void curar() {
            vida += 10;
            if (vida > vidaMaxima) vida = vidaMaxima;
            cout << nome << " curou-se. Vida atual: " << vida << endl;
        }
    };

   
    class Assasino : public Personagem {
    private: 
        int furtividade;

        public:
        Assasino(string Q, int E, int R) : Personagem(Q, E), furtividade(R) {}

        void atacar() {
            cout << nome << ": O assasino usou ataque das sombras!!! " << furtividade << "!" << endl;
        }
    };

    int main() {
        cout << "--- INICIO DA BATALHA ---" << endl;
    
        // Instanciar objetos
        Guerreiro g1("Thor", 100, 20); // Nome, Vida, Força
        Mago m1("Gandalf", 60, 35);    // Nome, Vida, Magia
        Assasino a1("Shevuc", 80, 15); // Nome, Vida, Furtividade
        // Usar métodos da classe Base (Getters)
        cout << "O guerreiro " << g1.getNome() << " entrou na arena." << endl;
        cout << "O mago " << m1.getNome() << " entrou na arena." << endl;
        cout << "O assasino " << a1.getNome() << " entrou na arena." << endl;
        cout << "\n--- COMBATE ---" << endl;
       
        // Guerreiro ataca (Método da derivada)
        g1.atacar(a1);
        g1.gritoDeGuerra(); // Método exclusivo
    
        // Mago recebe dano (Método da base herdado)
        m1.receberDano(20);

        if (a1.estaVivo()) {
            a1.atacar();
        }

        // Mago reage
        m1.atacar();
        m1.curar(); // Método exclusivo
   
        

        return 0;
    };
