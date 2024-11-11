





k,a,b= map(int,input().split())


import math
t = input()


s=len(t)

#print(s)

if a>s:
    print('No solution')
elif a==s:
    print(t)
elif a>math.ceil(s/k):
    print('No solution')
elif math.ceil(s/k)>b:
    print('No solution')
elif k>s:
    print('No solution')
else:



    if math.ceil(s/k) ==k:
        for j in range(0,s,k):
            print(t[j:j+k])
    else:
        if a==b:
            print('NO solution')
        else:
            l=[s//k]*k

            x = s-((s//k)*k)

            for j in range(x):
                l[j]+=1

            bg=[]
            hg=0
            if len(l)==1:
                pass
            else:
                for j in range(1,len(l)):
                    l[j]=l[j-1]+l[j]

                for g in range(len(l)):
                    if g==0:
                        if a<=len(t[:l[g]])<=b:
                            bg.append(t[:l[g]])
                        else:
                            print('No solution')
                            hg+=1
                            break
                    else:
                        if a<=len(t[l[g-1]:l[g]])<=b:
                            bg.append(t[l[g-1]:l[g]])
                        else:
                            print('No solution')
                            hg+=1
                            break
                        
                if hg==0:
                    for y in bg:
                        print(y)
                    

        
        
