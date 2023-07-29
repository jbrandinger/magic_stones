/* implement_hw.cpp
 *
 * implement solutions to magic stones and count flips algorithms from hw
 *
 * Created By: Joel Brandinger
 *
 * Date: April 2022
 */
#include "implement_hw.h"
#include <bits/stdc++.h>
#include <climits>

int solveBU(const vector<int> &stones, int health, vector<int> &memo);
int solveTD(const vector<int> &stones, int health, vector<int> &memo);
int sort(vector<int> &arr, vector<int> &temp, int left, int right);
int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right);

/* magicStonesBottomup(const vector<int> &stones, int health)
 *
 * Purpose: use a bottom up approach to solving the magic stones problem
 *
 * Parameters: vector of stone damages and health of dragon
 *
 * Returns: minimum number of stones needed to slay the dragon
 */
int magicStonesBottomup(const vector<int> &stones, int health)
{
    vector<int> memo(health + 1, INT_MAX);
    for (int i = 0; i <= health; i++) {
        memo[i] = solveBU(stones, i, memo);
    }
    return memo[health];
}

// Bottom Up helper function
int solveBU(const vector<int> &stones, int health, vector<int> &memo)
{
    if (health == 0) {
        return 0;
    } else {
        vector<int> arr;
        int length = stones.size();
        for (int i = 0; i < length; i++) {
            int prev_health = health - stones[i];
            if (prev_health >= 0) {
                if (memo[prev_health] != INT_MAX) {
                    arr.push_back(1 + memo[prev_health]);
                }
            }
        }
        if (!arr.empty()) {
            memo[health] = *min_element(arr.begin(), arr.end());
        }
        return memo[health];
    }
}

/* magicStonesTopdown(const vector<int> &stones, int health)
 *
 * Purpose: use a top down approach to solving the magic stones problem
 *
 * Parameters: vector of stone damages and health of dragon
 *
 * Returns: minmimum number of stones needed to slay the dragon
 */
int magicStonesTopdown(const vector<int> &stones, int health)
{
    vector<int> memo(health + 1, INT_MAX);
    return solveTD(stones, health, memo);
}

// Top Down helper function
int solveTD(const vector<int> &stones, int health, vector<int> &memo)
{
    if (health == 0) {
        return 0;
    } else {
        vector<int> arr;
        int length = stones.size();
        for (int i = 0; i < length; i++) {
            int prev_health = health - stones[i];
            if (prev_health >= 0) {
                if (memo[prev_health] == INT_MAX) {
                    memo[prev_health] = solveTD(stones, prev_health, memo);
                }
                if (memo[prev_health] != -1) {
                    arr.push_back(1 + memo[prev_health]);
                }
            }
        }
        if (arr.empty()) {
            memo[health] = -1; //no solution
        } else {
            memo[health] = *min_element(arr.begin(), arr.end());
        }
        return memo[health];
    }
}

/* countFlips(const vector<int> &arr)
 *
 * Purpose: count the number of flips in the given array using a modified 
 *          version of merge sort
 *
 * Parameters: array of numbers
 *
 * Returns: number of flips
 */
int countFlips(const vector<int> &arr)
{
    vector<int> sorted;
    for (long unsigned int i = 0; i < arr.size(); i++) {
        sorted.push_back(arr[i]);
    }
    vector<int> temp(arr.size(), 0);
    
    return sort(sorted, temp, 0, sorted.size() - 1);
}

// sorting function
int sort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int mid = 0;
    int count = 0;
    
    if (right > left) {
        mid = (right + left) / 2;
        count += sort(arr, temp, left, mid);
        count += sort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }
    
    return count;
}

// merge function that also updates flip counter
int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int count = 0;
 
    int left_idx = left;
    int right_idx = mid;
    int merge_idx = left;
    
    while ((left_idx <= mid - 1) && (right_idx <= right)) {
        if (arr[left_idx] <= arr[right_idx]) {
            temp[merge_idx] = arr[left_idx];
            merge_idx++;
            left_idx++;
        } else {
            temp[merge_idx] = arr[right_idx];
            merge_idx++;
            right_idx++;
            count = count + (mid - left_idx);
        }
    }

    while (left_idx <= mid - 1) {
        temp[merge_idx] = arr[left_idx];
        merge_idx++;
        left_idx++;
    }
 
    while (right_idx <= right) {
        temp[merge_idx] = arr[right_idx];
        merge_idx++;
        right_idx++;
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
 
    return count;
}