A = {'R':0, 'G':1, 'B':2, 'Y':3, 'W':4}

def bit_m(s):
    num = 1 << int(s[1])
    symb = 1 << (A[s[0]] + 6)
    return num | symb

n = int(input())
cards = list(set(input().split()))
res = [0 for i in range(len(cards))]
mask = [bit_m(cards[i]) for i in range(len(cards))]

def make_res(Q, cards):
    for i in range(len(cards)):
        if mask[i] & Q:
            res[i] |= Q
            
def check():
    for i in range(len(res)):
        for j in range(i + 1, len(res)):
            if res[i] == res[j]:
                return 0
    return 1
    

quest = [1 << i for i in range(10)]
cnt = 11
for i in range(0, 1023):
    cnt_now = 0
    res = [0 for i in range(len(cards))]
    for j in range(10):
        if (1 << j) & i != 0:
            cnt_now += 1
            make_res(quest[j], cards)
    if check():
        cnt = min(cnt, cnt_now)
print(cnt)
        