def main():
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]
    ans = n
    st = set(i for i in range(m))
    while len(st) > 1:
        dic = {v:0 for v in st}
        for i in range(n):
            for v in a[i]:
                if v in st:
                    dic[v] += 1
                    break
        tmp = max(dic.values())
        if ans > tmp:
            ans = tmp
        for key in dic.keys():
            if dic[key] == tmp:
                st.remove(key)
    print(ans)

if __name__ == "__main__":
    main()