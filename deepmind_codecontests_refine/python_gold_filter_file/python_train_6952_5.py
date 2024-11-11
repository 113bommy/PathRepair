def match(x, y):
    """
    １文字x, yが一致するか少なくとも一方が？であればTrueを返す。
    """
    return x == y or x == "?" or y == "?"


def func(a, b, c, la, lb, lc):
    """
    文字列の並びがa->b->cの場合を仮定して考える。
    aに対するb, cの配置が高々2000 * 2000通りあるので、文字列が一致するかの判定はO(1)でしないとTLE。
    これは先にaとb、bとc、aとcに対して文字列の一致を前処理確認しておけばOK <= 思いつかなかったので反省。

    ab[i] = (b[0]をa[i]から重ねたとき、合成文字列は一致するか)
    bc[i] = (c[0]をb[i]から重ねたとき、合成文字列は一致するか)
    ac[i] = (c[0]をa[i]から重ねたとき、合成文字列は一致するか)
    とおく。後ろに[True] * 2000を付け加えているのはaとbがdisjointな場合を考慮するため。
    """
    ab = [True] * (la + 4000)
    bc = [True] * (lb + 4000)
    ac = [True] * (la + 4000)

    for i in range(la):
        for j in range(min(la - i, lb)):
            if not match(a[i + j], b[j]):
                ab[i] = False
                break

    for i in range(lb):
        for j in range(min(lb - i, lc)):
            if not match(b[i + j], c[j]):
                bc[i] = False
                break

    for i in range(la):
        for j in range(min(la - i, lc)):
            if not match(a[i + j], c[j]):
                ac[i] = False
                break
    #print("ab={}".format(ab[:la]))
    #print("bc={}".format(bc[:lb]))
    #print("ac={}".format(ac[:la]))
    """
    前処理終わり。これより実際の比較を行う。
    """
    ans = la + lb + lc
    for i in range(la + 1):
        for j in range(max(lb + 1, la - i + 1)): # A上でBとCがdisjointに乗っかっている場合、j <= lbだと不十分(ex: A = "qaawbbe", B = "aa", C = "bb")
            if ab[i] and bc[j] and ac[i + j]:
                preans = max(la, i + lb, i + j + lc) # ここ(i + lb)入れないと、Bが一番長い場合が抜け落ちる
                ans = min(ans, preans)
    #print("{}->{}->{}: ans={}".format(a, b, c, ans))
    return ans


def main():
    a = input()
    b = input()
    c = input()
    la = len(a)
    lb = len(b)
    lc = len(c)
    ans = func(a, b, c, la, lb, lc)
    ans = min(ans, func(a, c, b, la, lc, lb))
    ans = min(ans, func(b, a, c, lb, la, lc))
    ans = min(ans, func(b, c, a, lb, lc, la))
    ans = min(ans, func(c, a, b, lc, la, lb))
    ans = min(ans, func(c, b, a, lc, lb, la))
    print(ans)

if __name__ == "__main__":
    main()
