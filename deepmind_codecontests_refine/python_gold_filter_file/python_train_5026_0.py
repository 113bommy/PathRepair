if __name__ == "__main__":
    ok, no = "Ya", "Tidak"

    T = int(input())
    for _ in range(T):
        A, B, C, D = map(int, input().split())
        answer = ["" for _ in range(4)]

        if (A + B) % 2 == 0:
            answer[0], answer[1] = no, no
            if B > 0 or C > 0:
                answer[2] = ok
                if A > 0 or D > 0:
                    answer[3] = ok
                else:
                    answer[3] = no
            else:
                answer[2] = no
                answer[3] = ok
        else:
            answer[2], answer[3] = no, no
            if B > 0 or C > 0:
                answer[1] = ok
                if A > 0 or D > 0:
                    answer[0] = ok
                else:
                    answer[0] = no
            else:
                answer[1] = no
                answer[0] = ok
        print(" ".join(answer))