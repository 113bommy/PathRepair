t=int(input())
import operator
for _ in range(t):
    n=int(input())
    if(n==1):
        print(1)
    elif(n==2):
        print(1,2)
    else:
        lis=[]
        for i in range(n):
            lis.append(0)
        stack=[]
        lis[(n-1)//2]=1
        if(n%2==1):
            stack.append((-((n-1)//2-1),0,(n-1)//2-1))
            stack.append((-(n-1-((n-1)//2+1)),(n-1)//2+1,n-1))
        else:
            stack.append((-(n-1-((n-1)//2+1)),(n-1)//2+1,n-1))
            stack.append((-((n-1)//2-1),0,(n-1)//2-1))
        next=2
        j=0
        k=2
        prev=stack[0][0]
        while j<k:
            if(stack[j][0]!=prev):
                stack.sort(key = lambda x: (x[0], x[1]))
                prev=stack[j][0]
            i=stack[j]
            if(i[2]-i[1]==0):
                lis[i[1]]=next
            else:
                if((i[2]-i[1]+1)%2==0):
                    lis[(i[2]+i[1])//2]=next
                    if(i[2]!=(i[2]+i[1])//2):
                        stack.append((-(i[2]-((i[2]+i[1])//2+1)),(i[2]+i[1])//2+1,i[2]))
                        k+=1
                    if(i[1]!=(i[2]+i[1])//2):
                        stack.append((-((i[2]+i[1])//2-1-i[1]),i[1],(i[2]+i[1])//2-1))
                        k+=1
                else:
                    lis[(i[2]+i[1])//2]=next
                    if(i[1]!=(i[2]+i[1])//2):
                        stack.append((-((i[2]+i[1])//2-1-i[1]),i[1],(i[2]+i[1])//2-1))
                        k+=1
                    if(i[2]!=(i[2]+i[1])//2):
                        stack.append((-(i[2]-((i[2]+i[1])//2+1)),(i[2]+i[1])//2+1,i[2]))
                        k+=1
            next+=1
            j+=1
            print(lis,stack)
        for i in lis:
            print(i,end=" ")
        print()