A, B, C, D, E, F = map(int, input().split())

W = sorted(list({a*100*A + b*100*B for a in range(F // 100 // A + 1) for b in range(F // 100 // B + 1) if a*100*A + b*100*B <= F}))
S = [max([c*C + d*D for c in range(int((E*w / 100) / C) + 1) for d in range(int((E*w / 100) / D) + 1) if ((c*C + d*D)*100 <= E*w) and (c*C + d*D + w <= F)]) for w in W]
I = sorted([i for i in range(len(W))], key=lambda i : W[i]/(W[i] + S[i]) if W[i] > 0 else 1)[0]
print(A if W[I] == 0 else W[I] + S[I], S[I])