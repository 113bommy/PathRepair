A = input()
op = ["+", "-"]
for bit in range(1 << 3):
    ans = A[0]
    for i in range(3):
        ans += op[(bit >> i) & 1]+A[i+1]
    if eval(ans) == 7:
        print(ans+"=7")
        break
