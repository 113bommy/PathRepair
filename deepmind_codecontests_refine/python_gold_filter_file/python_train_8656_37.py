# I attribute my success to this: I never gave or took any excuse. Florence Nightingale
# by : Blue Edge - Create some chaos

for _ in range(int(input())):
    n=int(input())
    s=input()
    try:
        res = (n-s.index("8"))>=11
    except:
        res=False

    print("YNEOS"[not res::2])
