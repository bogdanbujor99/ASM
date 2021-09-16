
#include <iostream>
using namespace std;


//INVERSUL SI VERIFICAREA DACA ESTE PALINDROM
/*int main() {
	int s,n,a;
	cin >> n;
	_asm {
		mov esi,0
		mov edi,n
		mov ebx,0
		mov ecx,10
		mov edx,0
		C1:
		mov eax,edi
        div ecx
		mov edi,eax
		mov eax,esi
        mov ebx,edx
        mul ecx
		add eax,ebx
		mov esi,eax
		mov edx,0
		cmp edi,edx
			jne C1
		mov s,esi
		mov eax,n
		cmp eax,esi
			je C2
		cmp eax,esi
			jne C3
		C2:
		   mov ebx,1
		   mov a,ebx
		   jmp C4
		 C3:
		   mov ebx,0
		   mov a,ebx
	     C4:
	}
	cout << "inversul numarului este=" << s << endl;
    if(a==1)cout<<"este palindrom";
	else cout<<"nu este palindrom";
}*/


//SCADEREA A DOI TERMENI
/*int scadere(int a,int b) {
	_asm {
		mov eax,a
		mov ebx,b
		sub eax,ebx
	}
 }
int main() {
	int a, b;
	cin >> a >> b;
	_asm {
		mov ebx,b
		mov eax,a
		push ebx
		push eax
		call scadere
		add esp,8
		mov a,eax
	}
	cout << a;
}*/


//VERIFICARE NR PRIM
/*int prim() {
	_asm {
		mov eax,[ebp+8]
		mov edi,[ebp+8]
		mov ecx,2
		mov edx,0
		cmp eax,1
		jle C2
		C1:
		mov eax,[ebp+8]
		div ecx
		cmp edx,0
		je C2
		mov edx,0
		add ecx,1
		cmp ecx,edi
		jl C1
		jmp C4
		C2:
	    mov eax,0
		jmp C5
		C4:mov eax,1
		C5:
  }
}
int main() {
	int n;
	cin >> n;
	_asm {
		mov eax, n
		push eax
		call prim
		add esp, 4
		mov n,eax
	}
	cout << n;
}*/


//CIFRA MAXIMA DINTR-UN NR DE 3 CIFRE
/*int ciframax() {
	_asm {
		mov eax,[ebp+8]
		mov edx,0
		mov ebx,10
		div ebx
		mov esi,edx
		mov edx,0
		div ebx
		mov edi,edx
		cmp esi,edi
		  jl C1
		  jmp C2
		C1:
		mov esi,edi
		C2:
		mov edx,0
		div ebx
		mov edi,edx
		cmp esi,edi
			jl C1
		mov eax,esi
	}
}

int main() {
	int n;
	cin >> n;
	_asm {
		push n
		call ciframax
		add esp,4
		mov n,eax
	}
	cout << n;
}*/

//NR PRIME INTRE ELE
/*int divizibile(int a, int b) {
	_asm {
		mov eax,a
		mov ebx,b
		mov edx,0
		C1:
		mov edx,0
		div ebx
        mov eax,ebx
		mov ebx,edx
        cmp ebx,0
		jne C1
		cmp eax,1
			jne C3
		jmp C4
		C3: mov eax,0
        C4:
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	_asm {
		push b
		push a
		call divizibile
		add esp,8
		mov a,eax
	}
	cout << a;
 }*/

//lea eax,v //incarc adresa vectorului
//[reg] sau [reg+reg*sizeof(element)]// pt adresa unui element
// byte pt char,word pt short, dword pt int

/*int main() {
	int v[3], i;
	_asm {
		//incarc adresa vectorului in eax
		lea eax,v
		//vreau sa pun pe pozitia 1 valoarea 5
		mov ecx,1
		mov dword ptr [eax+ecx*4],5
		//vreau sa pun in ebx valoarea de pe pozitia 1
		mov ebx, dword ptr [eax+ecx*4]
	}

	_asm {
		//vreau sa initializez fiecare loc din vector cu indexul 
		mov edx,0
	    lea eax,v
		c1:
		mov dword ptr[eax + edx * 4], edx
		add edx, 1
		cmp edx,2
		jle c1
	}
	for (i = 0; i <= 2; i++) {
		cout << v[i] << endl;
	}
}*/

//dpohsbut -1

/*int main(){
	char v[10] = "dpohsbut";
_asm {
	lea eax, v
	mov edx, 0
	c1:
	mov bl, byte ptr[eax + edx * 1]
	sub bl, 1
	mov byte ptr[eax + edx * 1],bl
	add edx,1
	cmp edx, 7
	jle c1
}
cout << v;
}*/

// matrice accesare elemnt a+(i*nr coloane+j*sizeof(element))

struct numarCustom {
	int a;
	int b;
};

/*int main() {
	//initializam structura cu 1 si cu 2
	//dupa care facem suma elementelor din structura
	numarCustom myNumber;
	int suma = 0;
	_asm {
		lea eax, myNumber
		mov dword ptr [eax],1
		mov dword ptr [eax+4],2
		mov ebx , dword ptr [eax]
		mov ecx , dword ptr [eax+4]
		add ebx,ecx
		mov suma,ebx
	}
	cout << myNumber.a << " " << myNumber.b << endl;
	cout << suma;
}*/



/*int strAdd(char* sir, unsigned int sirMaxLeght, char *toAdd ) {
	_asm {
		mov edi, [ebp+8] //sir
		mov eax, [ebp+12] 
		mov esi, [ebp+16] //toAdd
		mov edx,0//sir
		mov ecx,0//toAdd
		cmp byte ptr [edi+edx],0
		   je C3
		C1:
		    add edx,1
		    cmp byte ptr[edi + edx], 0
		    jne C1
         
		    cmp byte ptr[esi+ecx],0
		    je C3
		C2:
		    add ecx,1
		    cmp byte ptr[esi+ecx],0
			jne C2
       
		C3: 
			add edx,ecx
			cmp eax, edx
				jle C5
			sub edx, ecx
			mov eax, ecx
			mov ecx, 0
		C4 :
			mov bl, byte ptr[esi + ecx]
			mov byte ptr[edi + edx], bl
			add ecx,1
			add edx,1
			cmp ecx,eax
			    jl C4

		C5:

	}
}
int main() {
	char s1[30] = "Ana ";
	char s2[10] = "are mere";
	unsigned int n = 30;
	_asm {
		lea eax,s2
		push eax
		push n
		lea eax,s1
		push eax
		call strAdd
		add esp,12
	}
	cout << s1;
	return 0;
}*/


/*
struct rect {
	int x, y;
	int width;
	int height;
};

int intersectie(int* dreptungi1, int* dreptunghi2) {

	_asm {
		mov eax, [ebp + 8]
		mov ebx, [ebp + 12]
		mov esi, 0
		mov ecx, dword ptr[ebx]
		cmp dword ptr[eax], ecx
		jl C1
		jmp C5
		C1 : add esi, 1
		mov ecx, dword ptr[ebx + 4]
		cmp ecx, dword ptr[eax + 4]
		jl C2
		jmp C5
		C2 : add esi, 1
		mov ecx, dword ptr[ebx + 8]
		cmp ecx, dword ptr[eax + 8]
		jl C3
		jmp C5
		C3 : add esi, 1
		mov ecx, dword ptr[ebx + 12]
		cmp ecx, dword ptr[eax + 12]
		jl C4
		jmp C5
		C4 : add esi, 1
		C5 : mov eax,esi
	}

}

int main() {
	int ok = 0;
	rect dreptunghi1,dreptunghi2;
	_asm{
		lea eax, dreptunghi1
		lea ebx, dreptunghi2
		mov dword ptr [eax],4
		mov dword ptr [eax+4],4
		mov dword ptr [eax+8],6
		mov dword ptr [eax+12],8
		mov dword ptr[ebx],3
		mov dword ptr[ebx + 4],5
		mov dword ptr[ebx + 8],7
		mov dword ptr[ebx + 12],9
		push ebx
		push eax
		call intersectie
		add esp,8
		cmp eax,4
		je C1
		lea eax, dreptunghi1
		lea ebx, dreptunghi2
		mov dword ptr[eax], 4
		mov dword ptr[eax + 4], 4
		mov dword ptr[eax + 8], 6
		mov dword ptr[eax + 12], 8
		mov dword ptr[ebx], 3
		mov dword ptr[ebx + 4], 5
		mov dword ptr[ebx + 8], 7
		mov dword ptr[ebx + 12], 9
		push eax
		push ebx
		call intersectie
		add esp,8
		cmp eax, 4
		je C2
		C1: mov ok,eax
		jmp C3
		C2:mov ok,eax
		C3:
	}
	cout << ok;
}*/


/*
int GetNumarVocala(char* s) {
	int nr;
	_asm {
		mov ebx, [ebp + 8]
		mov eax, 0
		mov ecx, -1
		
		C1:
		add ecx,1
		cmp byte ptr [ebx+ecx],0
		je C3
		cmp byte ptr [ebx+ecx], 'a'
			je C2
		cmp byte ptr[ebx + ecx], 'e'
			je C2
		cmp byte ptr[ebx + ecx], 'i'
			je C2
		cmp byte ptr[ebx + ecx], 'o'
			je C2
		cmp byte ptr[ebx + ecx], 'u'
			je C2
		jmp C1

		C2:
		    mov edx, ecx
			add edx, 1
			cmp byte ptr[ebx + edx], 0
			je C1
			cmp byte ptr[ebx + edx], 'a'
			je C1
			cmp byte ptr[ebx + edx], 'e'
			je C1
			cmp byte ptr[ebx + edx], 'i'
			je C1
			cmp byte ptr[ebx + edx], 'o'
			je C1
			cmp byte ptr[ebx + edx], 'u'
			je C1
			cmp byte ptr[ebx + edx], ' '
			je C1
			add eax, 1
			jmp C1

        C3:mov nr,eax

	}
}

int main() {
	char s[30] = "azi o sa iau zece";
	int nr;
	_asm {
		lea eax,s
		push eax
		call GetNumarVocala
		add esp,4
		mov nr,eax
	}
	cout << nr;
	return 0;
}
*/

// matrice accesare elemnt a+(i*nr coloane+j*sizeof(element))
//LA VECTOR SI MATRICI AI GRIJA SA PUI LA DECLARARE EXACT NR DE ELEMENTE PE CARE IL FOLOSESTI
//DE EX: DACA AI DE PUS ELEMENTELE 1,2,3,4 DECLARAREA O SA FIE int v[4]={1,2,3,4}

//suma cifrelor pare ale unui numar

/*int suma(int x) {
	_asm {
		mov eax,[ebp+8]
		mov ecx,0
		jmp C1
		C2:
		add ecx,edx
		C1:
		cmp eax,0
			je C3
		mov edx,0
		mov ebx,10
        div ebx
        cmp edx,2
			je C2
		cmp edx, 4
			je C2
		cmp edx, 6
			je C2
		cmp edx, 8
			je C2
		jmp C1
		C3:
		mov eax,ecx
	}
}

int main() {
	int x;
	cin >> x;
	_asm {
		mov eax,x
		push eax
		call suma
		add esp,4
		mov x,eax
	}
	cout << x;
}
*/

//umratorul program cauta cate aparitii ale unei litere sunt

/*int main() {
	int nr;
	char s[10] = "aanna";
	_asm {
		lea eax, s
		mov ebx, -1
		mov edx, 0

		jmp C1

		C2 :
		add edx, 1

			C1 :
			add ebx, 1
			cmp byte ptr[eax + ebx], 0
			je C3
			cmp byte ptr[eax + ebx], 'n'
			je C2
			jmp C1

			C3 :
		mov nr, edx
	}
	cout << nr;
}
*/

//NUMARUL DE CUVINTE ALE UNEI PROPOZITII

/*int countCuvinte(char* sir) {
	_asm {
		mov ebx,[ebp+8]
		mov eax,0
		mov ecx,-1

		C1:
		add ecx,1
		cmp byte ptr[ebx+ecx], ' '
			je C2
		cmp byte ptr[ebx+ecx], 0
			je C3
		jmp C1

		C2:
		mov edx,ecx
		sub edx,1
		cmp byte ptr[ebx + edx], ' '
			je C1
		add eax,1
		jmp C1

		C3:
		mov edx, ecx
		sub edx, 1
		cmp byte ptr[ebx + edx], ' '
			je C5

		C4:add eax,1

        C5:

	}
}

int main() {
	char sir[20] = "ana are mere ";
	int nr;
	_asm {
		lea eax,sir
		push eax
		call countCuvinte
		add esp,4
		mov nr,eax
	}
	cout << nr;
}*/

//INTERCLASAREA

/*int ic(int* src1, int n1, int* src2, int n2, int* dst) {
	_asm {
		mov ecx, [ebp + 24]//dst
		//[ebp+12]=n1
		//[ebp+20]=n2
		mov edi,0//i
		mov esi,0//j
		mov edx,0//k

		C1:
		mov eax, [ebp + 8]//src1
		mov ebx, [ebp + 16]//src2
		mov eax, dword ptr[eax + edi * 4]
		mov ebx, dword ptr[ebx + esi * 4]
		cmp eax,ebx
			jle C2
		cmp ebx,eax
			jl C3


		C2:
		mov dword ptr[ecx+edx*4],eax
		add edx,1
		add edi,1
		cmp edi,[ebp+12]
			jl C1
		jmp C4

		C3:
		mov dword ptr[ecx + edx * 4],ebx
		add edx,1
		add esi,1
		cmp esi,[ebp+20]
			jl C1
		jmp C5

		C4:
		mov ebx,[ebp+16]
		mov eax, dword ptr [ebx+esi*4]
		mov dword ptr[ecx+edx*4],eax
		add edx,1
		add esi,1
		cmp esi, [ebp+20]
			jl C4
		jmp C6

		C5:
		mov eax,[ebp+8]
		mov ebx,dword ptr[eax+edi*4]
		mov dword ptr[ecx+edx*4],ebx
		add edx,1
		add edi,1
		cmp edi, [ebp+12]
			jl C5

		C6:mov eax,edx

	}
}

int main() {
	int src1[4] = { 1,5,7,8 };
	int src2[3] = { 2,4,6 };
	int dst[10];
	int n1 = 4, i, n2 = 3;
	_asm {
		lea eax,dst
		push eax
		mov eax,n2
		push eax
	    lea eax,src2
		push eax
		mov eax,n1
		push eax
		lea eax,src1
		push eax
		call ic
		add esp,20
		mov n1,eax
	}
	 
	for (i = 0; i <= n1 - 1; i++)cout << dst[i] << " ";

}
*/

//Distanta dintre doua puncte

/*struct punct {
	int x;
	int y;
};

int distanta(punct* A, punct* B) {
	_asm {
		mov eax, [ebp + 8]
		mov ebx, [ebp + 12]
		mov edi, dword ptr[eax]
		mov esi, dword ptr[ebx]
		sub edi,esi
		mov eax,edi
		mul edi
		mov ecx,eax
		mov eax, [ebp + 8]
		mov ebx, [ebp + 12]
		mov edi, dword ptr[eax+4]
		mov esi, dword ptr[ebx+4]
		sub edi, esi
		mov eax, edi
		mul edi
		add eax,ecx
	
	}
}

int main() {
	punct A, B;
	A.x = 3;
	A.y = 2;
	B.x = 4;
	B.y = 3;
	int dist;
	_asm {
		lea eax,B
		push eax
		lea eax, A
		push eax
		call distanta
		add esp,8
		mov dist,eax
	}
	cout << dist;
}
*/

//SORTARE

/*int sortare(int *v, int n) {
	_asm {
		mov eax, [ebp + 8]
		mov ebx, [ebp + 12]
		sub ebx,1
		mov ecx,-1

		C1:
		add ecx,1
		mov edx, ecx
		cmp ecx,ebx
			jl C2
		jmp C4

		C2:
		add edx,1
		cmp edx,ebx
			jle C3
		jmp C1

		C3:
		mov edi,dword ptr[eax+ecx*4]
		mov esi,dword ptr[eax+edx*4]
		cmp edi,esi
			jle C2
		mov dword ptr[eax + ecx * 4],esi
		mov dword ptr[eax + edx * 4],edi
		jmp C2

		C4:

	}
}

int main() {
	int v[9] = { 9,8,7,6,5,4,3,2,1 };
	int n = 9, i;
	_asm {
		mov eax,n
		push eax
		lea eax,v
		push eax
		call sortare
		add esp,8
	}
	for (i = 0; i <= n - 1; i++)cout << v[i] << " ";
}
*/

//PARCURGERE SI INITIALIZARE CU 1

/*int initializarematrice(int* a, int n, int m) {
	_asm {
		mov ebx,[ebp+12]
		mov ecx,[ebp+16]
		mov eax,4
		mul ecx
		mul ebx
		sub eax,4
		mov esi,eax
		mov eax, [ebp + 8]
		mov ebx,-4

		C1:
		add ebx,4
		cmp ebx,esi
			jle C2
		jmp C3

		C2:
		mov dword ptr[eax+ebx],1
		jmp C1

		C3:mov eax,esi

	}
}

int main() {
	int a[3][3], n = 3, m = 3, i, j;
	_asm {
		mov eax,m
		push eax
		mov eax,n
		push eax
		lea eax,a
		push eax
		call initializarematrice
		add esp,12
	}
	for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= m - 1; j++)cout << a[i][j] << " ";
		cout << endl;
	}

}
*/

//registri pt int: eax,ebx,ecx,edx,edi,esi
//registri pt short: ax,bx,cx,dx
//registri pt char:ah,al,bh,bl,ch,cl,dh,dl

/*
unsigned int Fibonacci(unsigned int n) {

	_asm {
		mov ebx,[ebp+8]
		mov eax, 0
		mov ecx, 1
		C1:
		cmp ebx,0
			je C2
		mov edx,ecx
		add ecx,eax
		mov eax,edx
		sub ebx,1
			jmp C1

		C2:

	}

}

int main() {
	unsigned int n;
	cin >> n;
	_asm {
		mov eax,n
		push eax
		call Fibonacci
		add esp,4
		mov n,eax
	}
	cout << n;
}
*/

int a = 0, b=0, c=1;

unsigned int Fibonacci(unsigned int n) {

	_asm {
		mov ebx, [ebp + 8]
		mov eax, b
		mov ecx, c
		mov edx,a
		C1:
		cmp edx,ebx
           je C2
		mov esi, ecx
		add ecx, eax
		mov eax, esi
		mov b,eax
		mov c,ecx
		sub ebx, 1
		add esp,4
		push ebx
		call Fibonacci
	
		C2:mov eax,b

	}
}

int main() {
	int n;
	cin >> n;
	_asm {
		mov eax,n
		push eax
		call Fibonacci
		add esp,4
		mov n,eax
	}
	cout << n;
}