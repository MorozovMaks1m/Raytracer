#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <memory>
#include <vector>

#include "hittable.h"

class HittableList : public Hittable {
public:
    HittableList() = default;
    HittableList(const std::shared_ptr<Hittable> &object) { Add(object); }

    void Clear() { objects_.clear(); }
    void Add(const std::shared_ptr<Hittable> &object) {
        objects_.push_back(object);
    }

    auto Hit(const Ray &ray, double t_min, double t_max,
             HitRecord &record) const -> bool override;

private:
    std::vector<std::shared_ptr<Hittable>> objects_;
};

#endif