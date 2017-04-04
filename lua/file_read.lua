function file_read(address)
    local file=io.open(address,"rb")
    file:seek("end",-128)
    str=file:read("*a")
    file:close()
    io.write(str)
end


