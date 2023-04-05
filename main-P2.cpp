#include<iostream>
#include<map>
#include<vector>
#include<string>
#include <algorithm> 
using namespace std;


class cell;
class genome
{
    private:
    string RNA;
    string DNA_p1;
    string DNA_p2;
    string DNA_RNA;
    friend class cell;


    public:
    map<char, char> mokamel;
    vector<int> count;
    vector<int> count2;
    
    
    genome()
    {
        mokamel.insert(pair<char , char > ('A','T'));
        mokamel.insert(pair<char , char > ('T','A'));
        mokamel.insert(pair<char , char > ('C','G'));
        mokamel.insert(pair<char , char > ('G','C'));
    }
    void get_gen()//daryaft mohtavaye gene
    {
        cout<<"ENTER RNA : ";
        cin>>RNA;
        cout<<"ENTER DNA FIRST PART : ";
        cin>>DNA_p1;
        cout<<"ENTER DNA SECOND PART : ";
        cin>>DNA_p2;

    }
    void make_dna(string rna)//sakht dna az rna
    {
        for (int i = 0 ; i<rna.length() ; i++)
        {
            if (rna[i] == 'A')
            {
                cout<<mokamel['A'];
            } 
            else if (rna[i] == 'T' )
            {
                cout<<mokamel['T'];
            }
            else if (rna[i] == 'G' )
            {
                cout<<mokamel['G'];
            }
            else if (rna[i] == 'C' )
            {
                cout<<mokamel['C'];
            }

        }
    }
    void small_jahesh_DNA(char a ,char b ,int c)//jahesh koochak dna
    {
        int test = 0;
        for (int i = 0 ; i<DNA_p1.length() ; i++)
        {

            if (DNA_p1[i] == a)
            {
                test++;
                DNA_p1[i] = b;


            }     
            if (test == c)
            {
                break;
            }
            if(DNA_p2[i] == a)
            {
                test ++;
                DNA_p2[i] = b;
            }
        
            if (test == c)
            {
                break;
            }
        }
    }
    void small_jahesh_RNA(char a ,char b ,int c)//jahesh koochak rna
    {
        count.clear();
        for (int i = 0 ; i<RNA.length();i++)
        {
            if(RNA[i] == a )
            {
                count.push_back(i);
            }
            
        }
    
        if(count.size() >= c)//age to reshte aval bood
        {
            for(int j = 0 ; j<c ; j++)
            {
                RNA[count[j]] = b;
            }
        }
    }
    void big_jahesh_RNA(string a , string b)//jaheshe bozorg rna
    {
        for( int i = 0 ; i< RNA.length() ; i++)
        {
            if ( RNA[i] == a[0])
            {
                if(RNA.substr(i , a.length()) == a)
                {
                    
                    RNA.erase(i,a.length());
                    RNA.insert(i,b);
                
                }
            }
        

        }
    }
    void big_jahesh_DNA(string a , string b)//jahesh bozorg Dna
    {
        int begin_p1 = 0;
        int begin_p2 = 0;
        for( int i = 0 ; i< DNA_p1.length() ; i++)
        {
            if ( DNA_p1[i] == a[0])
            {
                if(DNA_p1.substr(i , a.length()) == a)
                {
                    begin_p1 = i;
                }
            }
        }
        for( int i = 0 ; i< DNA_p2.length() ; i++)
        {
            if ( DNA_p2[i] == a[0])
            {
                if(DNA_p2.substr(i , a.length()) == a)
                    {
                    for (int j = 0 ; j < a.length(); j++)
                    {
                        begin_p2 = i;
                    } 
                }
            }
        }
        if(begin_p1>begin_p2)
        {
            DNA_p2.erase(begin_p2,a.length());

            DNA_p2.insert(begin_p2,b);
            DNA_p1.erase(begin_p2,a.length());
            string mokamel_b = b;
            for(int k = 0 ; k<b.length() ; k++)
            {
                mokamel_b[k] = mokamel[b[k]] ;

            }
            DNA_p1.insert(begin_p2,mokamel_b);
        }
    
        else
        {
            DNA_p1.erase(begin_p1,a.length());

            DNA_p1.insert(begin_p1,b);
            DNA_p2.erase(begin_p1,a.length());
            string mokamel_b = b;
            for(int k = 0 ; k<b.length() ; k++)
            {
                mokamel_b[k] = mokamel[b[k]] ;

            }
            DNA_p2.insert(begin_p2,mokamel_b);
        }
    
    }
    void reverse_jahesh_RNA(string a)//jaheshe makoos
    {
        for( int i = 0 ; i< RNA.length() ; i++)
        {
            if ( RNA[i] == a[0])
            {
                if(RNA.substr(i , a.length()) == a)
                {
                    
                    RNA.erase(i,a.length());
                    reverse(a.begin(), a.end()); 
                    RNA.insert(i,a);
                
                }
            }
        
    }
    
    
    
    
    
    
    
    
};
    void reverse_jahesh_DNA(string a)
    {
        int begin_p1 = 0;
        int begin_p2 = 0;
        for( int i = 0 ; i< DNA_p1.length() ; i++)
        {
            if ( DNA_p1[i] == a[0])
            {
                if(DNA_p1.substr(i , a.length()) == a)
                {
                    begin_p1 = i;
                }
            }
        }
        for( int i = 0 ; i< DNA_p2.length() ; i++)
        {
            if ( DNA_p2[i] == a[0])
            {
                if(DNA_p2.substr(i , a.length()) == a)
                    {
                    for (int j = 0 ; j < a.length(); j++)
                    {
                        begin_p2 = i;
                    } 
                }
            }
        }
        if(begin_p1>begin_p2)
        {
            DNA_p2.erase(begin_p2,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p2.insert(begin_p2,a);
            DNA_p1.erase(begin_p2,a.length());
            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]] ;

            }
            DNA_p1.insert(begin_p2,mokamel_a);
        }
    
        else
        {
            DNA_p1.erase(begin_p1,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p1.insert(begin_p1,a);
            DNA_p2.erase(begin_p1,a.length());
            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]] ;

            }
            DNA_p2.insert(begin_p2,mokamel_a);
        }
    
    }







};


class cell
{
    private:
    int n_chro;
    vector<string>DNA_p1_chro;
    vector<string>DNA_p2_chro;
    friend class genome;
    
    
    
    public:
    
    map<char, char> mokamel;
    cell()
    {
        mokamel.insert(pair<char , char > ('A','T'));
        mokamel.insert(pair<char , char > ('T','A'));
        mokamel.insert(pair<char , char > ('C','G'));
        mokamel.insert(pair<char , char > ('G','C'));
    }
    
    void get_gen_chro()
    {
        string DNA_p1;
        string DNA_p2;

        cout<<"ENTER  NUMBER OF chromosome: ";
        cin>>n_chro;
        for (int i = 0 ; i<n_chro ; i++)
        {
            cout<<"DNA of of "<<i+1<<"chromosome";
            cout<<"ENTER DNA_p1 OF CHRO"<<endl;
            cin>>DNA_p1;
            DNA_p1_chro.push_back(DNA_p1);
            cout<<"ENTER DNA_p2 OF CHRO";
            cin>>DNA_p2;
            DNA_p2_chro.push_back(DNA_p2);
        } 
    }


    void death_of_cell()
    {
         
        
        string dnap1;
        string dnap2;
        int n_of_d =0 ;
        for(int j = 0 ; j<n_chro ; j++)
        {
            dnap1 = DNA_p1_chro[j];
            dnap2 = DNA_p2_chro[j];

        
            for(int i = 0 ; i<dnap1.length() ; i++)
            {
                if(mokamel[dnap1[i]]== dnap2[i])
                {
                    n_of_d++;

                }     
            }
        

            if(n_of_d>=5)
            {
                DNA_p1_chro.erase(DNA_p1_chro.begin()+j);
                DNA_p2_chro.erase(DNA_p2_chro.begin()+j);
                n_chro = n_chro+1;
            }
        
        }
        
    }

    void big_rejahesh();

    void small_rejahesh();

    void rereverse();

    void pal_mok();

};



int main()
{
    
}