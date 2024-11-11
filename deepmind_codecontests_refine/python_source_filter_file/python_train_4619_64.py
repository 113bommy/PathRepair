n = int(input())
my_list=[]
for x in range(n):
    ans = input().split()
    my_list.append(ans)
k=0
problem = 0
for x in range (n):
    if my_list[k].count('1')>=2:
        problem +=1
        k+=1
print(problem)