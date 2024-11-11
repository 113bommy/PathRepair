def d_menagerie(N, S):
    s = S + S[0:2]  # 円環状に並んでいることを考慮
    for ans in ['SS', 'SW', 'WS', 'WW']:  # Sは羊、Wは狼。1番と2番の種類を仮定する
        for i in range(1, N + 1):
            if (ans[-1] == 'S' and s[i] == 'o') or (ans[-1] == 'W' and s[i] == 'x'):
                # この場合、今注目している動物の両隣は同じ種類。
                # よって、今注目している動物の右隣を左隣と同じにする。
                ans += ans[-2]
            else:
                # 両隣は違う種類。右隣を左隣と逆にする。
                ans += ('S' if ans[-2] == 'W' else 'W')
        if ans[:2] == ans[N:]:
            # sの最初の2文字(仮定)と最後の2文字が一致した文字列のみ受理する。
            # 1つ見つければ良いので、すぐにbreakする
            ans = ans[:N]
            break
    else:  # どの割り当て方も矛盾した
        ans = '-1'
    return ans

N = int(input())
S = input().strip()
print(d_Menagerie(N, S))