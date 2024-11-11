n = int(input())
a = list(map(int, input().split()))

ans = 0
current = 0
st = set()
st.add(0)
for item in a:
    current += item
    if current in st:
        st = set()
        st.add(0)
        ans += 1
        current = item
        st.add(current)

print(ans)

