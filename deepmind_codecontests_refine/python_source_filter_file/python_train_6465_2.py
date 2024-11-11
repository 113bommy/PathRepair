def check_k(k, a, x, n):
    for i in range(k, n+1):
        num = a[i] - a[i-1]
        index = (i-1) % k
        if x[index] == False:
            x[index] = num
        elif x[index] == num:
            continue
        else:
            return False
    return True


def main():
    n = int(input())
    a = [0] + [int(i) for i in input().split()]
    tot = 0
    res = ""
    x = []
    for k in range(1, n+1):
        x.append(False)
        if check_k(k, a, x, n):
            tot+=1
            res+=str(k)+ " "
    print(str(tot))
    print(res)

main()
