
a = list(map(int, input().split()))
b = list(map(int, input().split()))
n = int(input())
a_res = ((sum(a) +5)-1)//5
b_res = ((sum(b)+10)-1)//10
print("No" if (a_res + b_res) >n else "Yes")
