t=int(input())
def operate(lista,c):
        for i in range(c+1):
                if lista[i]=='1':
                        lista[i]='0'
                else:
                        lista[i]='1'
        lista1=lista[:c+1]
        lista2=lista[c:]
        lista1.reverse()
        lista=lista1+lista2
        return lista
for i in range(t):
        n=int(input())
        string1=input()
        string1=[j for j in string1]
        string2=input()
        string2=[j for j in string2]
        c=n-1
        lista=[]
        while (c>=0):
                if string1[c]!=string2[c]:
                        if string1[c]==string1[0]:
                                string1=operate(string1,c)
                                lista+=[c+1]
                        else:
                                string1=operate(string1,0)
                                string1=operate(string1,c)
                                lista+=[1,c+1]
                        c-=1
                else:
                        c=c-1
        print(len(lista),end=' ')
        for j in lista:
                print(j,end=' ')
        print("")
                
                                
