#include "cyclicList.h"

#include <gtest.h>

TEST(cyclicList, can_create_cyclicList_with_0_length)
{
  ASSERT_NO_THROW(cyclicList<int> m());
}

