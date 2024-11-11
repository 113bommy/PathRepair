def init():
    f[0] = 1
    for i in range(1, L):
        f[i] = (f[i - 1] * a) % table_size

def polyHash(keys):
    hashValue = 0
    for i in range(len(keys)):
        hashValue = (hashValue * a + ord(keys[i])) % table_size

    return hashValue
def check(query):
    h = polyHash(query)
    leng = len(query)
    for i in range(leng):
        for c in range(3):
            c_char = chr(ord('a') + c)
            if c_char == query[i]:
                continue
            new_hashValue = ((((ord(c_char) - ord(query[i])) * f[leng - i - 1]) % table_size + table_size) + h) % table_size
            if new_hashValue in dic:
                return True
    return False

L = 1000001
table_size = int(1e9) + 7
a = 257
f = [0] * L
init()
n, m = map(int,input().split())
dic = set()
for i in range(n):
    keys = input()
    dic.add(polyHash(keys))

buf = []
for i in range(m):
    t = input()
    buf.append('YES' if check(t) else 'NO')
print('\n'.join(buf))