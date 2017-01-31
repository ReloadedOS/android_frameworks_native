#include "include/private/dvr/buffer_hub_queue_consumer.h"

namespace android {
namespace dvr {

BufferHubQueueConsumer::BufferHubQueueConsumer(
    const std::shared_ptr<BufferHubQueueCore>& core)
    : core_(core) {}

}  // namespace dvr
}  // namespace android