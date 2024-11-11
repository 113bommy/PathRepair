# cf17-finalA - AKIBA
def main():
    S = input().rstrip()
    flg = (
        S.replace("A", "") == "KIHBR"
        and "AA" not in S
        and "KA" not in S
        and "AI" not in S
    )
    print("YES" if flg else "NO")


if __name__ == "__main__":
    main()