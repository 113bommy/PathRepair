# 最短ルートでいける、左上開始、右上終了ゆえに#の数数えればいけるぞ
H, W = map(int, input().split(" "))
A = [input() for _ in range(H)]

print(["Imbossible", "Possible"]["".join(A).count("#")==H+W-1])