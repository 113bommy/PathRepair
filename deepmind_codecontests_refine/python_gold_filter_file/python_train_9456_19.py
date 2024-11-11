n = list(input())
for i in range(8):
    ans = n[0]
    ans += '+-'[i%2] + n[1]
    ans += '+-'[i//4] + n[2]
    ans += '+-'[(i%4)//2] + n[3]
    if eval(ans) == 7:
        print(ans+"=7")
        break