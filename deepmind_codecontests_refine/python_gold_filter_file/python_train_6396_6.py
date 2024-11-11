n, k, x = input().split()
n = int(n)
k = int(k)
res = 0

arr = input().split()

for i in range(len(arr)):
    if(arr[i]==x):
        maior = 0
        copia = arr[0:i]+[x]+arr[i:len(arr)]
        teste = True
        while(teste):
            teste = False
            cont=1
            ini=0
            fim=0
            for j in range(1, len(copia)):
                if(copia[j]==copia[j-1]):
                    cont+=1
                    fim=j
                if(copia[j]!=copia[j-1] or j==len(copia)-1):
                    tmp = []
                    if(cont>=3):
                        tmp=copia[0:ini]
                        tmp+=copia[fim+1:len(copia)]
                        teste = True
                        copia=tmp
                        maior+=cont
                        break
                    cont=1
                    ini=j
                    fim=j

        if(maior>res):
            res=maior-1

print(res)