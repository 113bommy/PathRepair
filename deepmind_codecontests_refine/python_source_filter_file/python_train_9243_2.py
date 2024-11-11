
"""
Writer: SPD_9X2
https://atcoder.jp/contests/agc037/tasks/agc037_b

最適な配り方とは何かを考えるべき
そうすれば自然なdpに落ちるんだろうな

RGBが出たら合体させないといけない？
→これは正しそう

RGGRBB
112212 →4+3=7
112221 →5+2=7
121212 →4+4=8
なので、RGBが出たらランダムに合わせればいいわけではない

2つでたら合体しなければいけない説

RG→合体
GR→合体
B →2通り
B →1通り
なので2通り？
それっぽいぞ

BBRGRRGRGGRBBGB

B1/B
B1/B2
R2/RB,B
G2/B
R2/RB
R2/R,RB
G2/R
R2/R2
G4/RG,R
G4/RG2
R4/RG2,R
B8/RG,R
B8/R
G8/RG
B8/
8通り…少なすぎるな
あ、5!を掛ければ答えじゃね

あってるっぽさそう？
"""

N = int(input())
S = input()

R = 0
G = 0
B = 0
RG = 0
RB = 0
GB = 0

ans = 1
mod = 998244353
for i in range(1,N+1):
    ans *= i
    ans %= mod

for i in range(3*N):

    if S[i] == "R":
        if GB > 0:
            ans *= GB
            GB -= 1
        elif G > 0:
            ans *= G
            G -= 1
            RG += 1
        elif B > 0:
            ans *= B
            B -= 1
            RB += 1
        else:
            R += 1
            
    elif S[i] == "G":
        if RB > 0:
            ans *= RB
            RB -= 1
        elif R > 0:
            ans *= R
            R -= 1
            RG += 1
        elif B > 0:
            ans *= B
            B -= 1
            GB += 1
        else:
            G += 1

    else:
        if RG > 0:
            ans *= RG
            RG -= 1
        elif R > 0:
            ans *= R
            R -= 1
            RB += 1
        elif G > 0:
            ans *= G
            G -= 1
            RB += 1
        else:
            B += 1

    ans %= mod

print (ans)
