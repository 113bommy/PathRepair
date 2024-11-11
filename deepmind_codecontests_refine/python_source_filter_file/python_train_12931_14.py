a,b = map(int,input().split())
first_list = input().split()
second_list = input().split()
number_q = int(input())

def naming(x):
    f1 = x % a
    f2 = x % b
    ans = first_list[f1] + second_list[f2]
    print(ans)
    
for i in range(number_q):
    n = int(input())
    naming(n)