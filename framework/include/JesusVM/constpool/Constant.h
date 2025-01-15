#ifndef JESUSVM_CONSTANT_H
#define JESUSVM_CONSTANT_H

#include "types.h"

#include "JesusVM/Stack.h"

#include <memory>

namespace JesusVM {
	class Constant {
    public:
        virtual ~Constant() = default;

        enum class Type {
            FUNCTION,
        };

        virtual void addTo(Stack::Frame* frame) = 0;

    protected:
        explicit Constant(Type type)
            : mType(type) {}

        Type mType;
	};

	using ConstantPtr = std::unique_ptr<Constant>;
}

#endif // JESUSVM_CONSTANT_H
