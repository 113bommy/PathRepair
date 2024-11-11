def main():
    from operator import itemgetter
    n = int(input())
    d = {}
    for i in range(n):
        s = input()
        d[s] = i
    a = list(d.items())
    a.sort(key = itemgetter(1), reverse = True)
    for i in range(len(a)):
        print(a[i][0])
    
main()
