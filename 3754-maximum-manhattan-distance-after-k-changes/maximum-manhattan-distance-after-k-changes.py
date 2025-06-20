class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        maxMD = 0

        east  , west , north , south = 0 , 0 , 0 , 0

        n = len(s)

        for i in range(n):

            if s[i] == 'E':
                east += 1
            elif s[i] == 'W':
                west += 1
            elif s[i] == 'N':
                north += 1
            elif s[i] == 'S':
                south += 1

            currMD = abs(east - west) + abs(north - south)

            steps = i + 1
            
            wasted = steps - currMD

            extra = 0

            if wasted != 0:
                extra = min(2 * k , wasted)

            final_curr_MD = currMD + extra

            maxMD = max(maxMD , final_curr_MD)

        return maxMD
