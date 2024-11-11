t=int(input())
final_list=[]
for _ in range(t):
    line = input()
    final_list.append(tuple(line.split()))
for tup in final_list:
    x=int(tup[0])
    y=int(tup[1])
    if x<y: print("NO")
    elif x%2==1 and y%2==0: print("NO")
    elif x%2==y%2:
        print("YES")
        print('1 '*(y-1),end=''), print(x-y+1)
    elif x%2==0 and y%2==1:
        if x/2>y:
            print("YES")
            print('2 '*(y-1),end=''), print(x-2*(y-1))
        else: print("NO")