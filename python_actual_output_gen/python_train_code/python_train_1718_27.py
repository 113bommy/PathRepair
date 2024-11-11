n = list(map(int, input().split()))
if(n[0] + n[1] == 15):
    print("+")
elif(n[0] * n[1] == 15):
    print("*")
else:
    print("X")
