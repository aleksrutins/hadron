[indent=4]
uses
    Gee
    GtkSource

namespace Hadron.Util
    class BufferStorage
        buffers: ArrayList of Buffer
        construct()
            buffers = new ArrayList of Buffer
            