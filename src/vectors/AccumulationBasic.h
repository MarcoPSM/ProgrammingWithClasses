/*
 * Created by Marco Martins on 30-11-2025
 */

#ifndef PROGRAMACAOCOMCLASSES_ACCUMULATIONBASIC_H
#define PROGRAMACAOCOMCLASSES_ACCUMULATIONBASIC_H

#include <vector>

namespace mar {
class AccumulationBasic : public std::vector<int> {
public:
    AccumulationBasic(int capacity);
    virtual ~AccumulationBasic();

    virtual int                 PartialSum(int x, int y) const;
    virtual int                 Max(int x) const;
    virtual std::pair<int, int> BestLimits(int x) const;
};
} // namespace mar

#endif // PROGRAMACAOCOMCLASSES_ACCUMULATIONBASIC_H