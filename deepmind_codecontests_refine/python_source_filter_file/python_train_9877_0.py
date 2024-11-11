while True:
    try:
        x_a, y_a, x_b, y_b, x_c, y_c, x_d, y_d = map(float, input().split())
        ab_x, ab_y = x_b - x_a, y_b - y_a
        cd_x, cd_y = x_d - x_c, y_d - y_c
        dp = ab_x*cd_x + ab_y*cd_y
        if dp > 1e-10:
            print("NO")
        else:
            print("YES")
    except:
        break

