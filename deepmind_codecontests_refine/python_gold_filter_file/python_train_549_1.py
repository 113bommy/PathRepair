from fractions import Fraction


def solve(vp, vd, t, f, c):
    pos_dragon = -t*vd
    pos_princess = 0
    ans = 0

    while True:
        if vp < vd:
            time_dragon_overtake = Fraction(pos_princess-pos_dragon, vd-vp)
        else:
            time_dragon_overtake = float('infinity')

        time_princess_arrival = Fraction(c-pos_princess, vp)
        time = min(time_dragon_overtake, time_princess_arrival)

        pos_princess += vp*time
        pos_dragon += vd*time

        if pos_princess == c:
            return ans

        if pos_princess == pos_dragon:
            ans += 1
            pos_dragon = -pos_dragon - f*vd


if __name__ == "__main__":
    params = [int(input()) for _ in range(5)]
    ans = solve(*params)
    print(ans)
