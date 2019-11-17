class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums1.extend(nums2)
        nums1.sort()
        length = len(nums1)
        if (length + 1 )% 2 == 0:
            return nums1[(length-1)/2]
        else:
            return (nums1[(length-1)/2] + nums1[(length+1)/2])/2.0

