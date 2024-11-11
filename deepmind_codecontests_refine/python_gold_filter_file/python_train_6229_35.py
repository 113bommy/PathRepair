a, b = map(int, input().split())
print(100,100)

# 上半分を黒で塗っておく
def hoge(n, w=".", b="#"):
    for i in range(50):
        if i%2==0:
            print(b*100)
        else:
            l = [b]*100
            for j in range(min(25, n)):
                l[j*2] = w
            n -= min(25,n)
            print("".join(l))

hoge(a-1)
hoge(b-1,"#",".")