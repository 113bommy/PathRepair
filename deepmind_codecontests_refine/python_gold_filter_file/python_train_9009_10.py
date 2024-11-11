def main():
    n = int(input())
    total = 0
    list1 = []
    for i in range(n):
        a = int(input())
        list1.append(a)
    list1 = sorted(list1)
    for i in range(n):
        total = total + list1[i]*list1[n-i-1]
    print(total%10007)

main()
