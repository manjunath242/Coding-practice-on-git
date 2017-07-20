#pragma once
#include <vector>
class Solution4
{
public:
	Solution4();
	~Solution4();

		double findMedianSortedArrays() {
			
			std::vector<int> nums1, nums2;
			nums1.push_back(1);

			nums2.push_back(1);
			nums2.push_back(2);
			nums2.push_back(3);


			int n, m, total, temptotal;
			std::vector<int> finalVector;

			m = nums1.size();
			n = nums2.size();

			total = m + n;

			bool firstrun = true, even;
			int ref1 = 0, ref2 = 0;

			temptotal = 0;
			double median = 0;
			int med1 = 0, med2 = -1;

			if (total % 2 == 0)
			{
				even = true;
				med1 = (total / 2) - 1;
				med2 = (total / 2);
			}
			else
			{
				even = false;
				med1 = (total / 2);
			}

			if ((!nums1.empty()) && (!nums2.empty()))
			{
				for (int i = 0;i<total;i++)
				{
					

				if((ref1==m) || (ref2==n) && (!((ref1 == m) && (ref2 == n))))
					{
					
						if (ref1 == m)
						{
							finalVector.push_back(nums2.at(ref2));
							ref2++;
						}
						else if (ref2 == n)
						{
							finalVector.push_back(nums1.at(ref1));
							ref1++;
						}

					}

				else
				{

					if (nums1.at(ref1) > nums2.at(ref2))
					{
						finalVector.push_back(nums2.at(ref2));
						ref2++;
					}

					else if (nums2.at(ref2) > nums1.at(ref1))
					{
						finalVector.push_back(nums1.at(ref1));
						ref1++;
					}

					else if ((nums2.at(ref2) == nums1.at(ref1)))
					{
						finalVector.push_back(nums1.at(ref1));
						finalVector.push_back(nums2.at(ref2));
						ref1++;
						ref2++;
					}

				}

				temptotal = ref1 + ref2;

					if ((temptotal > med1))
					{
						if (even && ((finalVector.size()-1)>=(med2)))
						{
							median = (double)(finalVector.at(med1) + finalVector.at(med2)) / 2;
							break;
						}
						else if(!even)
						{
							median = (finalVector.at(med1));
							break;
						}

					}


				}
			}

			else
			{
				if (nums1.empty())
				{
					if (even)
					{
						median = (double)(nums2.at(med1) + nums2.at(med2)) / 2;
					}
					else
					{
						median = nums2.at(med1);
					}
				}

				else if (nums2.empty())
				{
					if (even)
					{
						median = (double)(nums1.at(med1) + nums1.at(med2)) / 2;
					}
					else
					{
						median = nums1.at(med1);
					}
				}

			}

			return median;



			/*int n, m;

			n = nums1.size();
			m = nums2.size();
			bool firstrun = true;

			double medn, medm;

			for (int i = 0;i<n;i++)
			{
				if (firstrun == true)
				{
					if ((n == 1 || n == 2))
					{
						medn = nums1.at(n - 1);
						break;
					}
					firstrun = false;
				}

				if ((n - 1) <= i)
				{
					if ((n - 1) == i)
					{
						medn = nums1.at(i);
						break;
					}
					else if ((n - 1)<i)
					{
						medn = (nums1.at(i) + nums1.at(n - 1)) / 2;
						break;
					}
				}
				n = n - 1;
			}

			firstrun = true;

			for (int i = 0;i<n;i++)
			{
				if (firstrun == true)
				{
					if ((m == 1 || m == 2))
					{
						medm = nums2.at(m - 1);
						break;
					}
					firstrun = false;
				}

				if ((m - 1) <= i)
				{
					if ((m - 1) == i)
					{
						medm = nums2.at(i);
						break;
					}
					else if ((m - 1)<i)
					{
						medm = (nums2.at(i) + nums2.at(m - 1)) / 2;
						break;
					}
				}
				m = m - 1;
			}


			medn = (medm + medn) / 2;
			return medn;  */
		}
};

