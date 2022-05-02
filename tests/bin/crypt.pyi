==================== SSR started ====================
SimpleScreenRecorder 0.3.11
Compiled with GCC 9.3.0
Qt: header 5.12.5, lib 5.12.8
libavformat: header 58.29.100, lib 58.29.100
libavcodec: header 58.54.100, lib 58.54.100
libavutil: header 56.31.100, lib 56.31.100
libswscale: header 5.5.100, lib 5.5.100
[CPUFeatures::Detect] CPU features: mmx sse sse2 sse3 ssse3 sse4_1 sse4_2 avx avx2 bmi1 bmi2
[ALSAInput::GetSourceList] Generating source list ...
[ALSAInput::GetSourceList] Found plugin: [samplerate] Rate Converter Plugin Using Samplerate Library
[ALSAInput::GetSourceList] Found plugin: [speexrate] Rate Converter Plugin Using Speex Resampler
[ALSAInput::GetSourceList] Found plugin: [jack] JACK Audio Connection Kit
[ALSAInput::GetSourceList] Found plugin: [oss] Open Sound System
[ALSAInput::GetSourceList] Found plugin: [upmix] Plugin for channel upmix (4,6,8)
[ALSAInput::GetSourceList] Found plugin: [vdownmix] Plugin for channel downmix (stereo) with a simple spacialization
[ALSAInput::GetSourceList] Found plugin: [usbstream] USB Stream Output
[ALSAInput::GetSourceList] Found card: [hw:0] HDA Intel PCH
[ALSAInput::GetSourceList] Found device: [hw:0,0] HDA Intel PCH: Generic Analog
[ALSAInput::GetSourceList] Found card: [hw:1] USB Audio Device
[ALSAInput::GetSourceList] Found device: [hw:1,0] USB Audio Device: USB Audio
[PulseAudioInput::GetSourceList] Generating source list ...
[SourceNamesCallback] Found source: [alsa_output.pci-0000_00_1f.3.analog-stereo.monitor] Monitor of Built-in Audio Analog Stereo
[SourceNamesCallback] Found source: [alsa_input.pci-0000_00_1f.3.analog-stereo] Built-in Audio Analog Stereo
[SourceNamesCallback] Found source: [alsa_output.usb-C-Media_Electronics_Inc._USB_Audio_Device-00.analog-stereo.monitor] Monitor of USB Audio Device Analog Stereo
[SourceNamesCallback] Found source: [alsa_input.usb-C-Media_Electronics_Inc._USB_Audio_Device-00.mono-fallback] USB Audio Device Mono
[PageRecord::StartPage] Starting page ...
[PageRecord::StartPage] Started page.
[PageRecord::StartInput] Starting input ...
[X11Input::Init] Using X11 shared memory.
[X11Input::InputThread] Input thread started.
[PulseAudioInput::InputThread] Stream is a monitor.
[PageRecord::StartInput] Started input.
[PulseAudioInput::InputThread] Input thread started.
[PageRecord::StartOutput] Starting output ...
[Muxer::Init] Using format matroska (Matroska).
[Muxer::AddStream] Using codec libx264 (libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10).
[VideoEncoder::PrepareStream] Using pixel format nv12.
[libx264 @ 0x5625061fc440] using SAR=1/1
[libx264 @ 0x5625061fc440] using cpu capabilities: MMX2 SSE2Fast SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
[libx264 @ 0x5625061fc440] profile High, level 4.0
[libx264 @ 0x5625061fc440] 264 - core 155 r2917 0a84d98 - H.264/MPEG-4 AVC codec - Copyleft 2003-2018 - http://www.videolan.org/x264.html - options: cabac=1 ref=1 deblock=1:0:0 analyse=0x3:0x3 me=dia subme=1 psy=1 psy_rd=1,00:0,00 mixed_ref=0 me_range=16 chroma_me=1 trellis=0 8x8dct=1 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=0 threads=12 lookahead_threads=2 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=3 b_pyramid=2 b_adapt=1 b_bias=0 direct=1 weightb=1 open_gop=0 weightp=1 keyint=250 keyint_min=25 scenecut=40 intra_refresh=0 rc=crf mbtree=0 crf=23,0 qcomp=0,60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1,40 pb_ratio=1,30 aq=1:1,00
[Muxer::AddStream] Using codec libvorbis (libvorbis).
[BaseEncoder::EncoderThread] Encoder thread started.
[AudioEncoder::PrepareStream] Using sample format f32p.
[BaseEncoder::EncoderThread] Encoder thread started.
[PageRecord::StartOutput] Started output.
[Synchronizer::SynchronizerThread] Synchronizer thread started.
[Muxer::MuxerThread] Muxer thread started.
[FastResampler::Resample] Resample ratio is 1.0000 (was 0.0000).
[PageRecord::StopOutput] Stopping output ...
[PageRecord::StopOutput] Stopped output.
[PageRecord::StopInput] Stopping input ...
[X11Input::~X11Input] Stopping input thread ...
[X11Input::InputThread] Input thread stopped.
[PulseAudioInput::~PulseAudioInput] Stopping input thread ...
[PulseAudioInput::InputThread] Input thread stopped.
[PageRecord::StopInput] Stopped input.
[PageRecord::StopPage] Stopping page ...
[Synchronizer::~Synchronizer] Stopping synchronizer thread ...
[Synchronizer::SynchronizerThread] Synchronizer thread stopped.
[Muxer::Finish] Finishing encoders ...
[BaseEncoder::EncoderThread] Flushing encoder ...
[BaseEncoder::EncoderThread] Encoder thread stopped.
[BaseEncoder::EncoderThread] Flushing encoder ...
[BaseEncoder::EncoderThread] Encoder thread stopped.
[Muxer::MuxerThread] Muxer thread stopped.
[Muxer::~Muxer] Stopping encoders ...
[Muxer::~Muxer] Waiting for muxer thread to stop ...
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[libx264 @ 0x5625061fc440] frame I:1     Avg QP:12,72  size:112979
[libx264 @ 0x5625061fc440] frame P:50    Avg QP:15,54  size:  9876
[libx264 @ 0x5625061fc440] frame B:126   Avg QP:18,63  size:  4419
[libx264 @ 0x5625061fc440] consecutive B-frames:  1,1%  4,5% 22,0% 72,3%
[libx264 @ 0x5625061fc440] mb I  I16..4: 70,7%  3,9% 25,4%
[libx264 @ 0x5625061fc440] mb P  I16..4:  2,9%  0,6%  0,5%  P16..4: 11,2%  0,0%  0,0%  0,0%  0,0%    skip:84,9%
[libx264 @ 0x5625061fc440] mb B  I16..4:  0,4%  0,1%  0,0%  B16..8:  6,3%  0,0%  0,0%  direct: 4,0%  skip:89,1%  L0:39,6% L1:36,6% BI:23,9%
[libx264 @ 0x5625061fc440] 8x8 transform intra:10,9% inter:22,7%
[libx264 @ 0x5625061fc440] coded y,uvDC,uvAC intra: 27,0% 25,3% 22,5% inter: 3,2% 1,4% 0,2%
[libx264 @ 0x5625061fc440] i16 v,h,dc,p: 59% 38%  3%  0%
[libx264 @ 0x5625061fc440] i8 v,h,dc,ddl,ddr,vr,hd,vl,hu: 10% 27% 42%  2%  3%  2%  5%  1%  7%
[libx264 @ 0x5625061fc440] i4 v,h,dc,ddl,ddr,vr,hd,vl,hu: 21% 47%  9%  3%  4%  3%  4%  3%  6%
[libx264 @ 0x5625061fc440] i8c dc,h,v,p: 67% 21% 11%  1%
[libx264 @ 0x5625061fc440] Weighted P-Frames: Y:0,0% UV:0,0%
[libx264 @ 0x5625061fc440] kb/s:1577,71
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[PageRecord::StopPage] Stopped page.
[PageRecord::StartPage] Starting page ...
[PageRecord::StartPage] Started page.
[PageRecord::StartInput] Starting input ...
[X11Input::Init] Using X11 shared memory.
[X11Input::InputThread] Input thread started.
[PulseAudioInput::InputThread] Stream is a monitor.
[PageRecord::StartInput] Started input.
[PulseAudioInput::InputThread] Input thread started.
[PageRecord::StopInput] Stopping input ...
[X11Input::~X11Input] Stopping input thread ...
[X11Input::InputThread] Input thread stopped.
[PulseAudioInput::~PulseAudioInput] Stopping input thread ...
[PulseAudioInput::InputThread] Input thread stopped.
[PageRecord::StopInput] Stopped input.
[PageRecord::StopPage] Stopping page ...
[PageRecord::StopPage] Stopped page.
[PageRecord::StartPage] Starting page ...
[PageRecord::StartPage] Started page.
[PageRecord::StartInput] Starting input ...
[X11Input::Init] Using X11 shared memory.
[X11Input::InputThread] Input thread started.
[PulseAudioInput::InputThread] Stream is not a monitor.
[PageRecord::StartInput] Started input.
[PulseAudioInput::InputThread] Input thread started.
[PageRecord::StartOutput] Starting output ...
[Muxer::Init] Using format matroska (Matroska).
[Muxer::AddStream] Using codec libx264 (libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10).
[VideoEncoder::PrepareStream] Using pixel format nv12.
[libx264 @ 0x562505c64940] using SAR=1/1
[libx264 @ 0x562505c64940] using cpu capabilities: MMX2 SSE2Fast SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
[libx264 @ 0x562505c64940] profile High, level 4.0
[libx264 @ 0x562505c64940] 264 - core 155 r2917 0a84d98 - H.264/MPEG-4 AVC codec - Copyleft 2003-2018 - http://www.videolan.org/x264.html - options: cabac=1 ref=1 deblock=1:0:0 analyse=0x3:0x3 me=dia subme=1 psy=1 psy_rd=1,00:0,00 mixed_ref=0 me_range=16 chroma_me=1 trellis=0 8x8dct=1 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=0 threads=12 lookahead_threads=2 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=3 b_pyramid=2 b_adapt=1 b_bias=0 direct=1 weightb=1 open_gop=0 weightp=1 keyint=250 keyint_min=25 scenecut=40 intra_refresh=0 rc=crf mbtree=0 crf=23,0 qcomp=0,60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1,40 pb_ratio=1,30 aq=1:1,00
[BaseEncoder::EncoderThread] Encoder thread started.
[Muxer::AddStream] Using codec libvorbis (libvorbis).
[AudioEncoder::PrepareStream] Using sample format f32p.
[BaseEncoder::EncoderThread] Encoder thread started.
[PageRecord::StartOutput] Started output.
[Muxer::MuxerThread] Muxer thread started.
[Synchronizer::SynchronizerThread] Synchronizer thread started.
[FastResampler::Resample] Resample ratio is 1.0000 (was 0.0000).
[PageRecord::StopOutput] Stopping output ...
[PageRecord::StopOutput] Stopped output.
[PageRecord::StopInput] Stopping input ...
[X11Input::~X11Input] Stopping input thread ...
[X11Input::InputThread] Input thread stopped.
[PulseAudioInput::~PulseAudioInput] Stopping input thread ...
[PulseAudioInput::InputThread] Input thread stopped.
[PageRecord::StopInput] Stopped input.
[PageRecord::StopPage] Stopping page ...
[Synchronizer::~Synchronizer] Stopping synchronizer thread ...
[Synchronizer::SynchronizerThread] Synchronizer thread stopped.
[Muxer::Finish] Finishing encoders ...
[BaseEncoder::EncoderThread] Flushing encoder ...
[BaseEncoder::EncoderThread] Flushing encoder ...
[BaseEncoder::EncoderThread] Encoder thread stopped.
[BaseEncoder::EncoderThread] Encoder thread stopped.
[Muxer::MuxerThread] Muxer thread stopped.
[Muxer::~Muxer] Stopping encoders ...
[Muxer::~Muxer] Waiting for muxer thread to stop ...
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[libx264 @ 0x562505c64940] frame I:197   Avg QP: 6,63  size:153198
[libx264 @ 0x562505c64940] frame P:12230 Avg QP:12,12  size:   479
[libx264 @ 0x562505c64940] frame B:36083 Avg QP:17,88  size:   122
[libx264 @ 0x562505c64940] consecutive B-frames:  0,8%  0,1%  0,1% 99,1%
[libx264 @ 0x562505c64940] mb I  I16..4: 70,7%  2,0% 27,3%
[libx264 @ 0x562505c64940] mb P  I16..4:  0,3%  0,0%  0,0%  P16..4:  0,4%  0,0%  0,0%  0,0%  0,0%    skip:99,3%
[libx264 @ 0x562505c64940] mb B  I16..4:  0,0%  0,0%  0,0%  B16..8:  0,1%  0,0%  0,0%  direct: 0,1%  skip:99,8%  L0:31,0% L1:66,3% BI: 2,7%
[libx264 @ 0x562505c64940] 8x8 transform intra:1,8% inter:24,1%
[libx264 @ 0x562505c64940] coded y,uvDC,uvAC intra: 24,8% 12,3% 11,5% inter: 0,1% 0,1% 0,0%
[libx264 @ 0x562505c64940] i16 v,h,dc,p: 89% 11%  0%  0%
[libx264 @ 0x562505c64940] i8 v,h,dc,ddl,ddr,vr,hd,vl,hu: 18% 24% 20% 10%  5%  4%  6%  4%  9%
[libx264 @ 0x562505c64940] i4 v,h,dc,ddl,ddr,vr,hd,vl,hu: 37% 24%  9%  5%  5%  5%  5%  5%  6%
[libx264 @ 0x562505c64940] i8c dc,h,v,p: 84%  7%  8%  1%
[libx264 @ 0x562505c64940] Weighted P-Frames: Y:0,0% UV:0,0%
[libx264 @ 0x562505c64940] kb/s:200,12
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[PageRecord::StopPage] Stopped page.
[PulseAudioInput::GetSourceList] Generating source list ...
[SourceNamesCallback] Found source: [alsa_output.pci-0000_00_1f.3.analog-stereo.monitor] Monitor of Built-in Audio Analog Stereo
[SourceNamesCallback] Found source: [alsa_input.pci-0000_00_1f.3.analog-stereo] Built-in Audio Analog Stereo
[SourceNamesCallback] Found source: [alsa_output.usb-C-Media_Electronics_Inc._USB_Audio_Device-00.analog-stereo.monitor] Monitor of USB Audio Device Analog Stereo
[SourceNamesCallback] Found source: [alsa_input.usb-C-Media_Electronics_Inc._USB_Audio_Device-00.mono-fallback] USB Audio Device Mono
[PageRecord::StartPage] Starting page ...
[PageRecord::StartPage] Started page.
[PageRecord::StartInput] Starting input ...
[X11Input::Init] Using X11 shared memory.
[X11Input::InputThread] Input thread started.
[PulseAudioInput::InputThread] Stream is not a monitor.
[PageRecord::StartInput] Started input.
[PulseAudioInput::InputThread] Input thread started.
[PageRecord::StartOutput] Starting output ...
[Muxer::Init] Using format matroska (Matroska).
[Muxer::AddStream] Using codec libx264 (libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10).
[VideoEncoder::PrepareStream] Using pixel format nv12.
[libx264 @ 0x5625061e6b00] using SAR=1/1
[libx264 @ 0x5625061e6b00] using cpu capabilities: MMX2 SSE2Fast SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
[libx264 @ 0x5625061e6b00] profile High, level 4.0
[libx264 @ 0x5625061e6b00] 264 - core 155 r2917 0a84d98 - H.264/MPEG-4 AVC codec - Copyleft 2003-2018 - http://www.videolan.org/x264.html - options: cabac=1 ref=1 deblock=1:0:0 analyse=0x3:0x3 me=dia subme=1 psy=1 psy_rd=1,00:0,00 mixed_ref=0 me_range=16 chroma_me=1 trellis=0 8x8dct=1 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=0 threads=12 lookahead_threads=2 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=3 b_pyramid=2 b_adapt=1 b_bias=0 direct=1 weightb=1 open_gop=0 weightp=1 keyint=250 keyint_min=25 scenecut=40 intra_refresh=0 rc=crf mbtree=0 crf=23,0 qcomp=0,60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1,40 pb_ratio=1,30 aq=1:1,00
[BaseEncoder::EncoderThread] Encoder thread started.
[Muxer::AddStream] Using codec libvorbis (libvorbis).
[AudioEncoder::PrepareStream] Using sample format f32p.
[BaseEncoder::EncoderThread] Encoder thread started.
[Muxer::MuxerThread] Muxer thread started.
[Synchronizer::SynchronizerThread] Synchronizer thread started.
[PageRecord::StartOutput] Started output.
[FastResampler::Resample] Resample ratio is 1.0000 (was 0.0000).
[PageRecord::StopOutput] Stopping output ...
[PageRecord::StopOutput] Stopped output.
[PageRecord::StopInput] Stopping input ...
[X11Input::~X11Input] Stopping input thread ...
[X11Input::InputThread] Input thread stopped.
[PulseAudioInput::~PulseAudioInput] Stopping input thread ...
[PulseAudioInput::InputThread] Input thread stopped.
[PageRecord::StopInput] Stopped input.
[PageRecord::StopPage] Stopping page ...
[Synchronizer::~Synchronizer] Stopping synchronizer thread ...
[Synchronizer::SynchronizerThread] Synchronizer thread stopped.
[Muxer::Finish] Finishing encoders ...
[BaseEncoder::EncoderThread] Flushing encoder ...
[BaseEncoder::EncoderThread] Flushing encoder ...
[BaseEncoder::EncoderThread] Encoder thread stopped.
[BaseEncoder::EncoderThread] Encoder thread stopped.
[Muxer::MuxerThread] Muxer thread stopped.
[Muxer::~Muxer] Stopping encoders ...
[Muxer::~Muxer] Waiting for muxer thread to stop ...
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[libx264 @ 0x5625061e6b00] frame I:6     Avg QP: 6,64  size:124808
[libx264 @ 0x5625061e6b00] frame P:318   Avg QP:11,44  size:   221
[libx264 @ 0x5625061e6b00] frame B:939   Avg QP:18,16  size:    93
[libx264 @ 0x5625061e6b00] consecutive B-frames:  0,9%  0,0%  0,0% 99,1%
[libx264 @ 0x5625061e6b00] mb I  I16..4: 74,8%  2,0% 23,2%
[libx264 @ 0x5625061e6b00] mb P  I16..4:  0,2%  0,0%  0,0%  P16..4:  0,2%  0,0%  0,0%  0,0%  0,0%    skip:99,6%
[libx264 @ 0x5625061e6b00] mb B  I16..4:  0,0%  0,0%  0,0%  B16..8:  0,0%  0,0%  0,0%  direct: 0,1%  skip:99,9%  L0:27,5% L1:72,5% BI: 0,0%
[libx264 @ 0x5625061e6b00] 8x8 transform intra:1,8% inter:5,7%
[libx264 @ 0x5625061e6b00] coded y,uvDC,uvAC intra: 21,4% 12,0% 11,2% inter: 0,0% 0,1% 0,0%
[libx264 @ 0x5625061e6b00] i16 v,h,dc,p: 89% 11%  0%  0%
[libx264 @ 0x5625061e6b00] i8 v,h,dc,ddl,ddr,vr,hd,vl,hu: 17% 21% 22% 12%  6%  5%  6%  4%  8%
[libx264 @ 0x5625061e6b00] i4 v,h,dc,ddl,ddr,vr,hd,vl,hu: 34% 24% 12%  5%  5%  5%  5%  5%  5%
[libx264 @ 0x5625061e6b00] i8c dc,h,v,p: 80%  7% 12%  1%
[libx264 @ 0x5625061e6b00] Weighted P-Frames: Y:0,0% UV:0,0%
[libx264 @ 0x5625061e6b00] kb/s:172,20
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[PageRecord::StopPage] Stopped page.
[PageRecord::StartPage] Starting page ...
[PageRecord::StartPage] Started page.
[PageRecord::StartInput] Starting input ...
[X11Input::Init] Using X11 shared memory.
[X11Input::InputThread] Input thread started.
[PulseAudioInput::InputThread] Stream is a monitor.
[PageRecord::StartInput] Started input.
[PulseAudioInput::InputThread] Input thread started.
[PageRecord::StartOutput] Starting output ...
[Muxer::Init] Using format matroska (Matroska).
[Muxer::AddStream] Using codec libx264 (libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10).
[VideoEncoder::PrepareStream] Using pixel format nv12.
[libx264 @ 0x562507b91800] using SAR=1/1
[libx264 @ 0x562507b91800] using cpu capabilities: MMX2 SSE2Fast SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
[libx264 @ 0x562507b91800] profile High, level 4.0
[libx264 @ 0x562507b91800] 264 - core 155 r2917 0a84d98 - H.264/MPEG-4 AVC codec - Copyleft 2003-2018 - http://www.videolan.org/x264.html - options: cabac=1 ref=1 deblock=1:0:0 analyse=0x3:0x3 me=dia subme=1 psy=1 psy_rd=1,00:0,00 mixed_ref=0 me_range=16 chroma_me=1 trellis=0 8x8dct=1 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=0 threads=12 lookahead_threads=2 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=3 b_pyramid=2 b_adapt=1 b_bias=0 direct=1 weightb=1 open_gop=0 weightp=1 keyint=250 keyint_min=25 scenecut=40 intra_refresh=0 rc=crf mbtree=0 crf=23,0 qcomp=0,60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1,40 pb_ratio=1,30 aq=1:1,00
[BaseEncoder::EncoderThread] Encoder thread started.
[Muxer::AddStream] Using codec libvorbis (libvorbis).
[AudioEncoder::PrepareStream] Using sample format f32p.
[BaseEncoder::EncoderThread] Encoder thread started.
[Muxer::MuxerThread] Muxer thread started.
[Synchronizer::SynchronizerThread] Synchronizer thread started.
[PageRecord::StartOutput] Started output.
[FastResampler::Resample] Resample ratio is 1.0000 (was 0.0000).
[PageRecord::StopOutput] Stopping output ...
[PageRecord::StopOutput] Stopped output.
[PageRecord::StopInput] Stopping input ...
[X11Input::~X11Input] Stopping input thread ...
[X11Input::InputThread] Input thread stopped.
[PulseAudioInput::~PulseAudioInput] Stopping input thread ...
[PulseAudioInput::InputThread] Input thread stopped.
[PageRecord::StopInput] Stopped input.
[PageRecord::StopPage] Stopping page ...
[Synchronizer::~Synchronizer] Stopping synchronizer thread ...
[Synchronizer::SynchronizerThread] Synchronizer thread stopped.
[Muxer::Finish] Finishing encoders ...
[BaseEncoder::EncoderThread] Flushing encoder ...
[BaseEncoder::EncoderThread] Flushing encoder ...
[BaseEncoder::EncoderThread] Encoder thread stopped.
[BaseEncoder::EncoderThread] Encoder thread stopped.
[Muxer::MuxerThread] Muxer thread stopped.
[Muxer::~Muxer] Stopping encoders ...
[Muxer::~Muxer] Waiting for muxer thread to stop ...
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[libx264 @ 0x562507b91800] frame I:7     Avg QP: 6,83  size:140020
[libx264 @ 0x562507b91800] frame P:400   Avg QP:10,92  size:   599
[libx264 @ 0x562507b91800] frame B:1180  Avg QP:16,36  size:   103
[libx264 @ 0x562507b91800] consecutive B-frames:  0,8%  0,3%  0,2% 98,8%
[libx264 @ 0x562507b91800] mb I  I16..4: 73,0%  2,0% 25,0%
[libx264 @ 0x562507b91800] mb P  I16..4:  0,5%  0,0%  0,1%  P16..4:  0,4%  0,0%  0,0%  0,0%  0,0%    skip:99,0%
[libx264 @ 0x562507b91800] mb B  I16..4:  0,0%  0,0%  0,0%  B16..8:  0,0%  0,0%  0,0%  direct: 0,1%  skip:99,8%  L0:51,7% L1:48,2% BI: 0,1%
[libx264 @ 0x562507b91800] 8x8 transform intra:1,6% inter:6,1%
[libx264 @ 0x562507b91800] coded y,uvDC,uvAC intra: 22,5% 10,9% 10,2% inter: 0,0% 0,1% 0,0%
[libx264 @ 0x562507b91800] i16 v,h,dc,p: 91%  8%  0%  0%
[libx264 @ 0x562507b91800] i8 v,h,dc,ddl,ddr,vr,hd,vl,hu: 18% 21% 21% 13%  6%  4%  7%  3%  7%
[libx264 @ 0x562507b91800] i4 v,h,dc,ddl,ddr,vr,hd,vl,hu: 34% 25% 11%  5%  5%  5%  5%  5%  5%
[libx264 @ 0x562507b91800] i8c dc,h,v,p: 83%  6% 10%  0%
[libx264 @ 0x562507b91800] Weighted P-Frames: Y:0,0% UV:0,0%
[libx264 @ 0x562507b91800] kb/s:202,83
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[PageRecord::StopPage] Stopped page.
[PageRecord::StartPage] Starting page ...
[PageRecord::StartPage] Started page.
[PageRecord::StartInput] Starting input ...
[X11Input::Init] Using X11 shared memory.
[X11Input::InputThread] Input thread started.
[PageRecord::StartInput] Started input.
[ALSAInput::InputThread] Input thread started.
[PageRecord::StopInput] Stopping input ...
[X11Input::~X11Input] Stopping input thread ...
[X11Input::InputThread] Input thread stopped.
[ALSAInput::~ALSAInput] Stopping input thread ...
[ALSAInput::InputThread] Input thread stopped.
[PageRecord::StopInput] Stopped input.
[PageRecord::StopPage] Stopping page ...
[PageRecord::StopPage] Stopped page.
[PulseAudioInput::GetSourceList] Generating source list ...
[SourceNamesCallback] Found source: [alsa_output.pci-0000_00_1f.3.analog-stereo.monitor] Monitor of Built-in Audio Analog Stereo
[SourceNamesCallback] Found source: [alsa_input.pci-0000_00_1f.3.analog-stereo] Built-in Audio Analog Stereo
[SourceNamesCallback] Found source: [alsa_output.usb-C-Media_Electronics_Inc._USB_Audio_Device-00.analog-stereo.monitor] Monitor of USB Audio Device Analog Stereo
[SourceNamesCallback] Found source: [alsa_input.usb-C-Media_Electronics_Inc._USB_Audio_Device-00.mono-fallback] USB Audio Device Mono
[PageRecord::StartPage] Starting page ...
[PageRecord::StartPage] Started page.
[PageRecord::StartInput] Starting input ...
[X11Input::Init] Using X11 shared memory.
[X11Input::InputThread] Input thread started.
[PulseAudioInput::InputThread] Stream is a monitor.
[PageRecord::StartInput] Started input.
[PulseAudioInput::InputThread] Input thread started.
[PageRecord::StartOutput] Starting output ...
[Muxer::Init] Using format matroska (Matroska).
[Muxer::AddStream] Using codec libx264 (libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10).
[VideoEncoder::PrepareStream] Using pixel format nv12.
[libx264 @ 0x5625062255c0] using SAR=1/1
[libx264 @ 0x5625062255c0] using cpu capabilities: MMX2 SSE2Fast SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
[libx264 @ 0x5625062255c0] profile High, level 4.0
[libx264 @ 0x5625062255c0] 264 - core 155 r2917 0a84d98 - H.264/MPEG-4 AVC codec - Copyleft 2003-2018 - http://www.videolan.org/x264.html - options: cabac=1 ref=1 deblock=1:0:0 analyse=0x3:0x3 me=dia subme=1 psy=1 psy_rd=1,00:0,00 mixed_ref=0 me_range=16 chroma_me=1 trellis=0 8x8dct=1 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=0 threads=12 lookahead_threads=2 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=3 b_pyramid=2 b_adapt=1 b_bias=0 direct=1 weightb=1 open_gop=0 weightp=1 keyint=250 keyint_min=25 scenecut=40 intra_refresh=0 rc=crf mbtree=0 crf=23,0 qcomp=0,60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1,40 pb_ratio=1,30 aq=1:1,00
[BaseEncoder::EncoderThread] Encoder thread started.
[Muxer::AddStream] Using codec libvorbis (libvorbis).
[AudioEncoder::PrepareStream] Using sample format f32p.
[BaseEncoder::EncoderThread] Encoder thread started.
[Muxer::MuxerThread] Muxer thread started.
[PageRecord::StartOutput] Started output.
[Synchronizer::SynchronizerThread] Synchronizer thread started.
[FastResampler::Resample] Resample ratio is 1.0000 (was 0.0000).
[PageRecord::StopOutput] Stopping output ...
[PageRecord::StopOutput] Stopped output.
[PageRecord::StopInput] Stopping input ...
[X11Input::~X11Input] Stopping input thread ...
[X11Input::InputThread] Input thread stopped.
[PulseAudioInput::~PulseAudioInput] Stopping input thread ...
[PulseAudioInput::InputThread] Input thread stopped.
[PageRecord::StopInput] Stopped input.
[PageRecord::StopPage] Stopping page ...
[Synchronizer::~Synchronizer] Stopping synchronizer thread ...
[Synchronizer::SynchronizerThread] Synchronizer thread stopped.
[Muxer::~Muxer] Stopping encoders ...
[Muxer::~Muxer] Waiting for muxer thread to stop ...
[BaseEncoder::EncoderThread] Encoder thread stopped.
[BaseEncoder::EncoderThread] Encoder thread stopped.
[Muxer::MuxerThread] Muxer thread stopped.
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[libx264 @ 0x5625062255c0] frame I:1     Avg QP:11,01  size: 95381
[libx264 @ 0x5625062255c0] frame P:27    Avg QP:13,63  size:  1205
[libx264 @ 0x5625062255c0] frame B:80    Avg QP:14,18  size:   119
[libx264 @ 0x5625062255c0] consecutive B-frames:  0,9%  0,0%  0,0% 99,1%
[libx264 @ 0x5625062255c0] mb I  I16..4: 76,6%  3,1% 20,3%
[libx264 @ 0x5625062255c0] mb P  I16..4:  0,5%  0,0%  0,0%  P16..4:  1,8%  0,0%  0,0%  0,0%  0,0%    skip:97,8%
[libx264 @ 0x5625062255c0] mb B  I16..4:  0,1%  0,0%  0,0%  B16..8:  0,1%  0,0%  0,0%  direct: 0,2%  skip:99,7%  L0:22,4% L1:77,6% BI: 0,0%
[libx264 @ 0x5625062255c0] 8x8 transform intra:2,7% inter:12,1%
[libx264 @ 0x5625062255c0] coded y,uvDC,uvAC intra: 18,8% 13,9% 12,4% inter: 0,1% 0,3% 0,1%
[libx264 @ 0x5625062255c0] i16 v,h,dc,p: 84% 16%  0%  0%
[libx264 @ 0x5625062255c0] i8 v,h,dc,ddl,ddr,vr,hd,vl,hu: 16% 22% 18% 10%  6%  4%  7%  4% 13%
[libx264 @ 0x5625062255c0] i4 v,h,dc,ddl,ddr,vr,hd,vl,hu: 33% 29% 10%  4%  5%  5%  5%  4%  6%
[libx264 @ 0x5625062255c0] i8c dc,h,v,p: 68% 14% 17%  0%
[libx264 @ 0x5625062255c0] Weighted P-Frames: Y:0,0% UV:0,0%
[libx264 @ 0x5625062255c0] kb/s:305,37
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[libvorbis @ 0x5625063165c0] 34 frames left in the queue on closing
[PageRecord::StopPage] Stopped page.
[PageRecord::StartPage] Starting page ...
Cannot connect to server socket err = No such file or directory
Cannot connect to server request channel
jack server is not running or cannot be started
JackShmReadWritePtr::~JackShmReadWritePtr - Init not done for -1, skipping unlock
JackShmReadWritePtr::~JackShmReadWritePtr - Init not done for -1, skipping unlock
[1;31m[JACKInput::Init] Error: Could not connect to JACK![0m
[1;31m[PageRecord::StartPage] Error: Something went wrong during initialization.[0m
[PageRecord::StartPage] Started page.
[PageRecord::StartInput] Starting input ...
[X11Input::Init] Using X11 shared memory.
[PageRecord::StartInput] Started input.
[X11Input::InputThread] Input thread started.
[PageRecord::StartOutput] Starting output ...
[Muxer::Init] Using format matroska (Matroska).
[Muxer::AddStream] Using codec libx264 (libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10).
[VideoEncoder::PrepareStream] Using pixel format nv12.
[libx264 @ 0x562507f8cd00] using SAR=1/1
[libx264 @ 0x562507f8cd00] using cpu capabilities: MMX2 SSE2Fast SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
[libx264 @ 0x562507f8cd00] profile High, level 4.0
[libx264 @ 0x562507f8cd00] 264 - core 155 r2917 0a84d98 - H.264/MPEG-4 AVC codec - Copyleft 2003-2018 - http://www.videolan.org/x264.html - options: cabac=1 ref=1 deblock=1:0:0 analyse=0x3:0x3 me=dia subme=1 psy=1 psy_rd=1,00:0,00 mixed_ref=0 me_range=16 chroma_me=1 trellis=0 8x8dct=1 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=0 threads=12 lookahead_threads=2 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=3 b_pyramid=2 b_adapt=1 b_bias=0 direct=1 weightb=1 open_gop=0 weightp=1 keyint=250 keyint_min=25 scenecut=40 intra_refresh=0 rc=crf mbtree=0 crf=23,0 qcomp=0,60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1,40 pb_ratio=1,30 aq=1:1,00
[Muxer::AddStream] Using codec libvorbis (libvorbis).
[BaseEncoder::EncoderThread] Encoder thread started.
[AudioEncoder::PrepareStream] Using sample format f32p.
[BaseEncoder::EncoderThread] Encoder thread started.
[Muxer::MuxerThread] Muxer thread started.
[PageRecord::StartOutput] Started output.
[Synchronizer::SynchronizerThread] Synchronizer thread started.
[PageRecord::StopOutput] Stopping output ...
[PageRecord::StopOutput] Stopped output.
[PageRecord::StopInput] Stopping input ...
[X11Input::~X11Input] Stopping input thread ...
[X11Input::InputThread] Input thread stopped.
[PageRecord::StopInput] Stopped input.
[PageRecord::StopPage] Stopping page ...
[Synchronizer::~Synchronizer] Stopping synchronizer thread ...
[Synchronizer::SynchronizerThread] Synchronizer thread stopped.
[Muxer::~Muxer] Stopping encoders ...
[Muxer::~Muxer] Waiting for muxer thread to stop ...
[BaseEncoder::EncoderThread] Encoder thread stopped.
[BaseEncoder::EncoderThread] Encoder thread stopped.
[Muxer::MuxerThread] Muxer thread stopped.
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[BaseEncoder::~BaseEncoder] Stopping encoder thread ...
[PageRecord::StopPage] Stopped page.
==================== SSR stopped ====================
