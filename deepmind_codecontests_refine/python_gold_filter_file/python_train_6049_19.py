n1=list(map(int,input().split(' ')))
n2 = list(map(int, input().split(' ')))
cost=0
mn=1 if n1[1]<n1[2] else 2
# while 2 in n2:
#     ind=n2.index(2)
#     index = -1*(ind-n1[0])-1
#     if n2[index] == 2:
#         n2[index] = mn-1
#         cost+=n1[mn] if ind!=index else 0
#     n2[ind] = n2[index]    
#     cost += n1[n2[ind]+1]
# if n2!=n2[::-1]:
#     print(-1)
# else:
#     print(cost)
i=0
while i<n1[0]//2:
    if n2[i]==2:
        if n2[-1*(i-n1[0])-1] == 2:
            # n2[i] = n2[-1*(i-n1[0])-1] = mn-1
            cost += 2*n1[mn]
        else:
            # n2[i] = n2[-1*(i-n1[0])-1]
            cost += n1[n2[-1*(i-n1[0])-1]+1]
    elif n2[-1*(i-n1[0])-1] ==2:
        # n2[-1*(i-n1[0])-1]=n2[i]
        cost += n1[n2[i]+1]
    elif n2[-1*(i-n1[0])-1]!=n2[i]:
        cost=-1
        break
    i+=1
if n1[0] % 2 == 1 and n2[i] == 2 and cost!=-1:
    # n2[i+1] = mn-1
    cost += n1[mn]
print(cost)
