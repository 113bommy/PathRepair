def main():
    """
    ロボットアーム

    腕、関節
        arm_1, arm_2,...,arm_m
    k_0,  k_1,   k_2,...,  k_m

    k_i-1, arm_i, k_i
    arm_i_length: d_i

    mode: L, R, D, U

        (x0, y0) = (0, 0)
        L: (x_i, y_i) = (x_i-1 - d_i, y_i-1)
        R: (x_i, y_i) = (x_i-1 + d_i, y_i-1)
        U: (x_i, y_i) = (x_i-1,       y_i-1 - d_i)
        D: (x_i, y_i) = (x_i-1,       y_i-1 + d_i)

    input:
            1 <= N  <= 10^3
        -10^9 <= Xi <= 10^9
        -10^9 <= Yi <= 10^9

    output:
        NG: -1
        OK:

        m
        d1 d2 ... dm
        w1
        w2
        ...
        wN

        1 <= m   <= 40
        1 <= d_i <= 10^12
        w_i: {L, R, U, D}, w_i_lenght = m

    動かし方の例は、入力例1参照
    """
    N = int(input())
    X, Y = zip(*(
        map(int, input().split())
        for _ in range(N)
    ))

    # m, d, w = part_300(N, X, Y)
    m, d, w = ref(N, X, Y)

    if m == -1:
        print(-1)
    else:
        print(m)
        print(*d)
        print(*w, sep="\n")


def ex1(N, X, Y):
    m = 2
    d = [1, 2]
    w = ["RL", "UU", "DR"]
    return m, d, w


def part_300(N, X, Y):
    """
    1つ1つのクエリに対する操作は独立
    ただし、使うパラメータm, d は共通

    部分点は以下の制約
       -10 <= i <= 10
       -10 <= i <= 10

    探索範囲
        20 * 20
        この範囲においてm<=40で到達するためのd
    d=1のとき|X|+|Y|の偶奇
        揃っている場合、mは最大に合わせる、余っているときはRLのように移動なしにできる
        揃っていない場合, d=1では不可能？
        2と1およびLR,UDを駆使して-1を再現して偶奇を揃える?
            無理っぽい: 奇数しか作れない
    """
    dists = []
    for x, y in zip(X, Y):
        dist = abs(x) + abs(y)
        dists.append(dist)

    m = -1
    d = []
    w = []
    mod = list(map(lambda x: x % 2, dists))
    if len(set(mod)) == 1:
        m = max(dists)
        d = [1] * m
        for x, y, dist in zip(X, Y, dists):
            x_dir = "R" if x > 0 else "L"
            y_dir = "U" if y > 0 else "D"

            _w = x_dir * abs(x) + y_dir * abs(y)
            rest = m - len(_w)
            if rest > 0:
                _w += "LR" * (rest // 2)
            w.append(_w)

    return m, d, w


def editorial(N, X, Y):
    """
    2冪の数の組合せにより、どの点にでも移動できるようになる
        ※ただし、奇数のみ。偶数に対応させたいときは１での移動を追加する

      1,   2,   4,   8,
    2^0, 2^1, 2^2, 2^3, ...

    {1} だけでの移動、原点からの1の距離。当たり前
    x: 原点
            b
    -------cxa------
            d

    {1, 2} での移動、原点から1の距離から2移動できる
    a-d を基準に考えると
        a-d をa方向に2移動: a方向に菱形の移動範囲が増える
        a-d をb方向に2移動: b
        a-d をc方向に2移動: c
        a-d をd方向に2移動: d
            b
           b b
          c b a
         c cxa a
          c d a
           d d
            d

    https://twitter.com/CuriousFairy315/status/1046073372315209728
    https://twitter.com/schwarzahl/status/1046031849221316608
    どうして(u, v)=(x+y, x-y)的な変換を施す必要があるのか？
        https://twitter.com/ILoveTw1tter/status/1046062363831660544
        http://drken1215.hatenablog.com/entry/2018/09/30/002900
             x 座標, y 座標両方頑張ろうと思うと、60 個くらい欲しくなる。で、困っていた。


         U
         |
    L----o----R
         |
         D

      U＼        ／R
         ＼    ／
           ＼／
           ／ ＼
         ／     ＼
      L／         ＼D
    """
    pass


def ref(N, X, Y):
    dists = []
    for x, y in zip(X, Y):
        dist = (abs(x) + abs(y)) % 2
        dists.append(dist)

    m = -1
    d = []
    w = []
    mod = set(map(lambda x: x % 2, dists))
    if len(mod) != 1:
        return m, d, w

    for i in range(30, 0-1, -1):
        d.append(1 << i)
    if 0 in mod:
        d.append(1)
    m = len(d)

    w = transform_xy(N, X, Y, d)
    # w = no_transform_xy(N, X, Y, d)
    # print(w)

    return m, d, w


def transform_xy(N, X, Y, d):
    w = []
    dirs = {
        # dir: x', y'
        (-1, -1): "L",  # 本来の座標(x, y): (-1,  0)
        (+1, +1): "R",  # 本来の座標(x, y): (+1,  0)
        (+1, -1): "U",  # 本来の座標(x, y): ( 0, +1)
        (-1, +1): "D",  # 本来の座標(x, y): ( 0, -1)
    }
    for x, y in zip(X, Y):
        x_sum = 0
        y_sum = 0
        _w = ""
        for _d in d:
            # 変換後の座標でx',y'を独立に求めている?
            if x_sum <= x:
                x_dir = 1
                x_sum += _d
            else:
                x_dir = -1
                x_sum -= _d

            if y_sum <= y:
                y_dir = 1
                y_sum += _d
            else:
                y_dir = -1
                y_sum -= _d

            _w += dirs[(x_dir, y_dir)]

        w.append(_w)

    return w


def no_transform_xy(N, X, Y, d):
    w = []
    for xt, yt in zip(X, Y):
        x, y = 0, 0
        _w = ""
        for _d in d:
            if abs(x - xt) >= abs(y - yt):
                if x >= xt:
                    x -= _d
                    _w += "L"
                else:
                    x += _d
                    _w += "R"
            else:
                if y >= yt:
                    y -= _d
                    _w += "D"
                else:
                    y += _d
                    _w += "U"

        w.append(_w)

    return w


if __name__ == '__main__':
    main()
