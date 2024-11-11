



maxn = 100000+7
n,m = map(int, input().split())
a = list(map(int, input().split()))

b = [None]*maxn
st = set()

def dele(n) :
    for i in range(1, n) :
        b[i] -= 1
def update(n) :
    st.clear()
    for i in range(1, n) :
        if(b[i] > 0) :
            st.add(i)

#main
for i in range(maxn) :
    b[i] = 0;

for i in a :
    b[i] += 1
    st.add(i)
    if len(st) == n :
        print(1, end='')
        dele(n)
        update(n)
    else :
        print(0, end='')
